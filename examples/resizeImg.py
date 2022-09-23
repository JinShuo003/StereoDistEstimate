import cv2 as cv
import os
from pathlib import Path


def ResizeImages(img_path, imgSize):
    img = cv.imread(str(img_path))
    des = cv.resize(img, imgSize)
    cv.imwrite(str(img_path), des)


def main():
    img_file_dir = Path(r'./images/Middlebury')
    left_img_path = img_file_dir.joinpath('cam0.png')
    right_img_path = img_file_dir.joinpath('cam1.png')
    disparyty_img_path = img_file_dir.joinpath('disparity_cam0.png')
    depth_img_path = img_file_dir.joinpath('depth_cam0.png')
    ResizeImages(left_img_path, (960, 540))
    ResizeImages(right_img_path, (960, 540))
    ResizeImages(disparyty_img_path, (960, 540))
    ResizeImages(depth_img_path, (960, 540))


if __name__ == '__main__':
    main()
