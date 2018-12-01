
#include "ColorTransfer.h"

ColorTransfer::ColorTransfer(const Mat &source, const Mat &target)
{
    // CV_8UC3��ͼ��ת��ΪCV_64FC3
    source.convertTo(source_, CV_64FC3, 1. / 255.);
    target.convertTo(target_, CV_64FC3, 1. / 255.);
    result_ = source_.clone();  // deep copy

    Transfer();
}

void ColorTransfer::RGB2Lab(const Mat &img_rgb, Mat &img_lab)
{
    try
    {
        img_lab = img_rgb.clone();
        for (int i = 0; i < img_rgb.rows; ++i)
        {
            double R, G, B;
            for (int j = 0; j < img_rgb.cols; ++j)
            {
                // R:(i,j)[2]; G:(i,j)[1]; B:(i,j)[0]
                R = img_rgb.at<Vec3d>(i, j)[2];
                G = img_rgb.at<Vec3d>(i, j)[1];
                B = img_rgb.at<Vec3d>(i, j)[0];

                // RGB -> LMS
                double L = 0.3811 * R + 0.5783 * G + 0.0402 * B;
                double M = 0.1967 * R + 0.7244 * G + 0.0782 * B;
                double S = 0.0241 * R + 0.1288 * G + 0.8444 * B;

                // LMSȡ��10Ϊ�׵Ķ���
                L = (L > 0) ? log10(L) : 0;
                M = (M > 0) ? log10(M) : 0;
                S = (S > 0) ? log10(S) : 0;

                // LMS -> Lab
                img_lab.at<Vec3d>(i, j)[0] = (L + M + S) / sqrt(3.);
                img_lab.at<Vec3d>(i, j)[1] = (L + M - S * 2) / sqrt(6.);
                img_lab.at<Vec3d>(i, j)[2] = (L - M) / sqrt(2.);
            }
        }
    }
    catch (...)
    {
        std::cout << "Error: RGB2Lab" << std::endl;
    }
}

void ColorTransfer::Lab2RGB(const Mat &img_lab, Mat &img_rgb)
{
    try
    {
        img_rgb = img_lab.clone();
        for (int i = 0; i < img_lab.rows; ++i)
        {
            double l, a, b;
            for (int j = 0; j < img_lab.cols; ++j)
            {
                l = img_lab.at<Vec3d>(i, j)[0] / sqrt(3.);
                a = img_lab.at<Vec3d>(i, j)[1] / sqrt(6.);
                b = img_lab.at<Vec3d>(i, j)[2] / sqrt(2.);

                // Lab -> LMS
                double L = pow(10, l + a + b);
                double M = pow(10, l + a - b);
                double S = pow(10, l - a * 2);

                // LMS -> RGB
                double R = 4.4679*L - 3.5873*M + 0.1193*S;
                double G = -1.2186*L + 2.3809*M - 0.1624*S;
                double B = 0.0497*L - 0.2439*M + 1.2045*S;

                // ��ֹRGB������Χ
                if (R > 1.) { R = 1.; }
                else if (R < 0.) { R = 0.; }
                else {}
                if (G > 1.) { G = 1.; }
                else if (G < 0.) { G = 0.; }
                else {}
                if (B > 1.) { B = 1.; }
                else if (B < 0.) { B = 0.; }
                else {}
            
                img_rgb.at<Vec3d>(i, j) = Vec3d(B, G, R);
            }
        }
    }
    catch (...)
    {
        std::cout << "Error: Lab2RGB" << std::endl;
    }
}

void ColorTransfer::CalcMeanSd(const Mat &img, Mat &mean, Mat &sd)
{
    try
    {
        cv::meanStdDev(img, mean, sd);
    }
    catch(...)
    {
        std::cout << "Error: CalcMeanSd()" << std::endl;
    }
}

void ColorTransfer::Transfer()
{
    // Դͼ���Ŀ��ͼ����ɫ�ռ�任
    Mat sourceLab = source_.clone();
    Mat targetLab = target_.clone();
    RGB2Lab(source_, sourceLab);
    RGB2Lab(target_, targetLab);

    // ��ͨ������Դͼ���Ŀ��ͼ��ľ�ֵ����׼��
    Mat sourceMean(1, 1, CV_64FC3), sourceSd(1, 1, CV_64FC3);   // Scalar��Vec4dҲ����
    Mat targetMean(1, 1, CV_64FC3), targetSd(1, 1, CV_64FC3);
    CalcMeanSd(sourceLab, sourceMean, sourceSd);
    CalcMeanSd(targetLab, targetMean, targetSd);

    // ��ͨ�����㣬��ȥԴ�ľ�ֵ������Դ�ķ����Ŀ��ķ����Ŀ��ľ�ֵ
    Mat resultLab = sourceLab.clone();
    for (int c = 0; c < 3; ++c)  // "c" for "channel"
    {
        double s_mean = sourceMean.at<Vec3d>(0, 0)[c];
        double s_sd = sourceSd.at<Vec3d>(0, 0)[c];
        double t_mean = targetMean.at<Vec3d>(0, 0)[c];
        double t_sd = targetSd.at<Vec3d>(0, 0)[c];
        for (int row = 0; row < resultLab.rows; ++row)
        {
            for (int col = 0; col < resultLab.cols; ++col)
            {
                resultLab.at<Vec3d>(row, col)[c] =
                    (sourceLab.at<Vec3d>(row, col)[c] - s_mean) * (t_sd / s_sd) + t_mean;
            }
        }
    }

    // ���ͼ����ɫ�ռ�任
    Lab2RGB(resultLab, result_);
}