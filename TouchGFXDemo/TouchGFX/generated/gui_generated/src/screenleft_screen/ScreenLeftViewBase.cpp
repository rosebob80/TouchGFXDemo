/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screenleft_screen/ScreenLeftViewBase.hpp>
#include "BitmapDatabase.hpp"

ScreenLeftViewBase::ScreenLeftViewBase() :
    buttonCallback(this, &ScreenLeftViewBase::buttonCallbackHandler)
{

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_BG_LEFT_ID));

    textureMapper1.setXY(70, 30);
    textureMapper1.setBitmap(touchgfx::Bitmap(BITMAP_BLUE_LOGO_TOUCHGFX_LOGO_ID));
    textureMapper1.setWidth(180);
    textureMapper1.setHeight(180);
    textureMapper1.setBitmapPosition(26.000f, 26.000f);
    textureMapper1.setScale(1.000f);
    textureMapper1.setCameraDistance(1000.000f);
    textureMapper1.setOrigo(90.000f, 90.000f, 1000.000f);
    textureMapper1.setCamera(90.000f, 90.000f);
    textureMapper1.updateAngles(-0.500f, -0.500f, -0.500f);
    textureMapper1.setRenderingAlgorithm(touchgfx::TextureMapper::NEAREST_NEIGHBOR);

    buttonRight.setXY(278, 104);
    buttonRight.setBitmaps(touchgfx::Bitmap(BITMAP_ARROW_RIGHT_ID), touchgfx::Bitmap(BITMAP_ARROW_RIGHT_GRAY_ID));
    buttonRight.setAction(buttonCallback);

    add(image1);
    add(textureMapper1);
    add(buttonRight);
}

void ScreenLeftViewBase::setupScreen()
{

}

void ScreenLeftViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonRight)
    {
        //Interaction1
        //When buttonRight clicked change screen to ScreenCenter
        //Go to ScreenCenter with no screen transition
        application().gotoScreenCenterScreenNoTransition();
    }
}
