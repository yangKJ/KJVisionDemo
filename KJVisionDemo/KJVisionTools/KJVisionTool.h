//
//  KJVisionTool.h
//  KJVisionDemo
//
//  Created by 杨科军 on 2019/11/4.
//  Copyright © 2019 杨科军. All rights reserved.
//  Vision 封装工具

#import <Foundation/Foundation.h>
#import <Vision/Vision.h>
#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KJVisionModel : NSObject
// 包含该面部特征的的数组
@property (nonatomic, strong) NSMutableArray *allPoints;
//
@property (nonatomic, strong) VNFaceObservation *observation;
// 脸部轮廊
@property (nonatomic, strong) VNFaceLandmarkRegion2D *faceContour;
// 左眼，右眼
@property (nonatomic, strong) VNFaceLandmarkRegion2D *leftEye;
@property (nonatomic, strong) VNFaceLandmarkRegion2D *rightEye;
// 鼻子，鼻嵴
@property (nonatomic, strong) VNFaceLandmarkRegion2D *nose;
@property (nonatomic, strong) VNFaceLandmarkRegion2D *noseCrest;
@property (nonatomic, strong) VNFaceLandmarkRegion2D *medianLine;
// 外唇，内唇
@property (nonatomic, strong) VNFaceLandmarkRegion2D *outerLips;
@property (nonatomic, strong) VNFaceLandmarkRegion2D *innerLips;
// 左眉毛，右眉毛
@property (nonatomic, strong) VNFaceLandmarkRegion2D *leftEyebrow;
@property (nonatomic, strong) VNFaceLandmarkRegion2D *rightEyebrow;
// 左瞳,右瞳
@property (nonatomic, strong) VNFaceLandmarkRegion2D *leftPupil;
@property (nonatomic, strong) VNFaceLandmarkRegion2D *rightPupil;

@end

typedef NS_ENUM(NSUInteger,KJDetectFaceType) {
    KJDetectFaceTypeRectanglesRequest = 0, // 人脸矩形检测
    KJDetectFaceTypeLandmarksRequest, // 人脸特征识别
    KJDetectFaceTypeTextRectangles,   // 文字识别
};

typedef void (^KJVisionDatasBlock)(NSArray *datas);

@interface KJVisionTool : KJVisionModel

/// 识别图片
+ (void)kj_detectImageWithType:(KJDetectFaceType)type Image:(UIImage*)image Block:(KJVisionDatasBlock)block;

/// 在返回结果中的boundingBox中的坐标，我们并不能立即使用，而是需要进行转换
/// 因为这里是相对于image的一个比例，这里需要注意的是y坐标的转换，因为坐标系的y轴和UIView的y轴是相反的
/// 最后就是通过返回的坐标进行矩形的绘制
+ (UIImage*)kj_drawImage:(UIImage*)image Rects:(NSArray*)rects;

+ (UIImage *)kj_drawImage:(UIImage*)image Observation:(VNFaceObservation*)observation LandMarkPoints:(NSArray*)pointArray;

/// 动态识别
+ (void)kj_dynamicDetectFaceWithSuperView:(UIView*)view Block:(KJVisionDatasBlock)block;

@end

NS_ASSUME_NONNULL_END
