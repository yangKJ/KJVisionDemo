//
//  ViewController.m
//  KJVisionDemo
//
//  Created by 杨科军 on 2019/10/31.
//  Copyright © 2019 杨科军. All rights reserved.
//

#import "ViewController.h"
#import "KJVisionTool.h"
@interface ViewController ()
@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) NSMutableArray *temps;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.temps = [NSMutableArray array];
    [self.view addSubview:self.imageView];
    UIImage *image = [UIImage imageNamed:@"AAA"];
    self.imageView.image = image;
    [KJVisionTool kj_detectImageWithType:(KJDetectFaceTypeRectanglesRequest) Image:image Block:^(NSArray * _Nonnull datas) {
        self.imageView.image = [KJVisionTool kj_drawImage:image Rects:datas];
    }];
    return;
    
//    [KJVisionTool kj_detectImageWithType:(KJDetectFaceTypeLandmarksRequest) Image:image Block:^(NSArray * _Nonnull datas) {
//        if (datas.count) {
//            KJVisionModel *model = datas[0];
//            self.imageView.image = [KJVisionTool kj_drawImage:image Observation:model.observation LandMarkPoints:model.allPoints];
//        }
//    }];
//    return;
    
//    [KJVisionTool kj_dynamicDetectFaceWithSuperView:self.view Block:^(NSArray * _Nonnull datas) {
//        dispatch_async(dispatch_get_main_queue(), ^{
//            //先移除之前的矩形框
//            [self.temps makeObjectsPerformSelector:@selector(removeFromSuperlayer)];
////            AVCaptureDevicePosition position = [[self.avInput device] position];
//            for (VNFaceObservation *faceObservation in datas) {
//                //boundingBox
//                CGRect transFrame = kj_convertRect(faceObservation.boundingBox, self.view.frame.size);
////                //前置摄像头的时候 记得转换
////                if (position == AVCaptureDevicePositionFront){
////                    transFrame.origin.x = self.view.frame.size.width - transFrame.origin.x - transFrame.size.width;
////                }
//                CALayer *rectLayer = [CALayer layer];
//                rectLayer.frame = transFrame;
//                rectLayer.borderColor = [UIColor purpleColor].CGColor;
//                rectLayer.borderWidth = 2;
//                [self.view.layer addSublayer:rectLayer];
//                [self.temps addObject:rectLayer];
//            }
//        });
//    }];
}

- (UIImageView *)imageView{
    if (!_imageView) {
        _imageView = [[UIImageView alloc]initWithFrame:self.view.bounds];
        _imageView.contentMode = UIViewContentModeScaleAspectFit;
    }
    return _imageView;
}

@end

