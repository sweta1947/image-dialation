#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;
int main()
{
	int c = 0, a = 0;
	Mat var1 = imread("noise.jpg", 1);
	Mat var2(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	Mat var3(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	Mat var4(var1.rows, var1.cols, CV_8UC1, Scalar(0));
	cvtColor(var1, var2, CV_BGR2GRAY);

	namedWindow("windows3", WINDOW_AUTOSIZE);
	createTrackbar("dialate", "windows3", &a, 255);
	while (1){
		for (int i = 0; i < var1.rows; i++){
			for (int j = 0; j < var1.cols; j++)
			{
				if (var2.at<uchar>(i, j) < a)
				{
					var3.at<uchar>(i, j) = 0;
					var4.at<uchar>(i, j) = 0;
				}
				else
				{
					var3.at<uchar>(i, j) = 255;
					var4.at<uchar>(i, j) = 255;
				}
			}
		}
		for (int i = 1; i < var3.rows - 1; i++){
			for (int j = 1; j < var3.cols - 1; j++)
			{
				for (int m = i - 1; m <= i + 1; m++){
					for (int n = j - 1; n <= j + 1; n++)
					{
						if (var3.at<uchar>(m, n) == 255)
							c = 1;
					}
				}
				if (c == 1)
					var4.at<uchar>(i, j) = 255;
				c = 0;
			}
		}
		namedWindow("windows1", 1);
		imshow("windows1", var1);
		namedWindow("windows2", 1);
		imshow("windows2", var2);
		namedWindow("windows3", 1);
		imshow("windows3", var3);
		namedWindow("windows4", 1);
		imshow("windows4", var4);
		waitKey(10);
	}
	return (0);
}