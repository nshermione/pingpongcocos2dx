/****************************************************************************
B2DebugDrawLayer.h

Created by Stefan Nguyen on Oct 8, 2012.

Copyright (c) 2013 Stefan Nguyen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __B2_DEBUG_DRAW_LAYER_H__
#define __B2_DEBUG_DRAW_LAYER_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"

using namespace cocos2d;

class B2DebugDrawLayer : public Layer
{
  b2World* mB2World;
  GLESDebugDraw* mB2DebugDraw;
  const float mPtmRatio;
 
public:
  B2DebugDrawLayer(b2World* pB2World, float pPtmRatio);
  static B2DebugDrawLayer* create(b2World* pB2World, float pPtmRatio);
  virtual bool init();
  virtual void draw(Renderer *renderer, const Mat4& transform, bool transformUpdated);
    
protected:
    Mat4 _modelViewMV;
    void onDraw();
    CustomCommand _customCommand;

};

#endif // __B2_DEBUG_DRAW_LAYER_H__
