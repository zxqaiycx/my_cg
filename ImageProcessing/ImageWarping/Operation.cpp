
#include "Operation.h"

Operation::Operation()
{
}

Operation::Operation(const Mat& image, const std::string& windowName)
{
    // 初始化srcImage_，dstImage_
    srcImage_ = image.clone();
    showImage_ = image.clone();
    dstImage_ = (Mat(image.size(), image.type(), Scalar::all(255))).clone();

    // 初始化isChanged_
    int nrow = dstImage_.rows;
    int ncol = dstImage_.cols;
    isChanged_ = new bool*[nrow];
    for (int i = 0; i < nrow; ++i)
    {
        isChanged_[i] = new bool[ncol];
        for (int j = 0; j < ncol; ++j)
        {
            isChanged_[i][j] = false;
        }
    }

    // 初始化windowName_并显示srcImage_
    windowName_ = windowName;    
    imshow(windowName_, srcImage_);

    // 初始化isInput_
    isInput_ = true;
}

Operation::~Operation()
{
    int nrow = dstImage_.rows;
    for (int i = 0; i < nrow; ++i)
    {
        delete[] isChanged_[i];
        isChanged_[i] = NULL;
    }
    delete[] isChanged_;
    isChanged_ = NULL;
}

void Operation::OnMouse(int event, int x, int y, int flags, void* param)
{
    Mat& image = *(Mat*)param;

    switch (event)
    {
    case EVENT_LBUTTONDOWN:
    {
        if (isInput_)
        {
            p_.push_back(Point(x, y));
            circle(showImage_, Point(x, y), 3, Scalar(0, 0, 255), -1); // 画点
            this->Show();
        }
        break;
    }
    case EVENT_MOUSEMOVE:
    {
        break;
    }
    case EVENT_LBUTTONUP:
    {
        if (isInput_)
        {
            if (p_.back() == Point(x, y))
            {
                q_.push_back(Point(x, y));
            }
            else
            {
                q_.push_back(Point(x, y));
                line(showImage_, p_.back(), Point(x, y), Scalar(0, 127, 255), 1);
                circle(showImage_, Point(x, y), 3, Scalar(0, 255, 255), -1);
            }
            this->Show();
        }
        break;
    }
    case EVENT_RBUTTONDOWN:
    {
        if (isInput_)
        {
            isInput_ = false;
            this->WarpingIDW();
            this->Show();
        }
        else // 从头重来一次图像扭曲
        {
            isInput_ = true;
            showImage_ = srcImage_.clone();
            p_.swap(vector<Point>());
            q_.swap(vector<Point>());
            this->Show();
        }
        break;
    }
    default:
        break;
    }
}

void Operation::Show()
{
    if (isInput_)
    {
        imshow(windowName_, showImage_);
    }
    else
    {
        imshow(windowName_, dstImage_);
    }
}

void Operation::WarpingIDW()
{
    IDW idw(p_, q_, 2.);

    int nrow = srcImage_.rows;  // height
    int ncol = srcImage_.cols;  // width
    Point q;    // 点p(i,j)映射到的点
    for (int i = 0; i < nrow; ++i)
    {
        for (int j = 0; j < ncol; ++j)
        {
            q = idw.F(Point(j, i)); // ij不要弄反了
            if ((q.x >= 0 && q.x <= ncol-1) && (q.y >= 0 && q.y <= nrow - 1))
            {
                if (!isChanged_[q.y][q.x])
                {
                    dstImage_.at<Vec2b>(q.y, q.x) = srcImage_.at<Vec2b>(i, j);
                    isChanged_[q.y][q.x] = true;
                }
            }
        }
    }
}

void Operation::WarpingRBF()
{

}

void Operation::CompleteImage()
{

}