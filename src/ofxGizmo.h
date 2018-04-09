//
//  ofxGizmo.h
//  TerrainTest
//
//  Created by Nick Hardeman on 10/5/14.
//

#pragma once
#include "ofMain.h"
#include "IGizmo.h"

class ofxGizmo {
public:
    ofxGizmo();
    ~ofxGizmo();
    
    enum ofxGizmoType {
        OFX_GIZMO_MOVE = 0,
        OFX_GIZMO_SCALE,
        OFX_GIZMO_ROTATE
    };
    
    void setMatrix( ofMatrix4x4 aMat );
    bool setMatrix( string aString );
    void setNode( ofNode aNode );
    
    void draw( ofCamera& aCam );
    
    void setDisplayScale( float aScale );
    float getDisplayScale();
    void setType( ofxGizmoType aType );
    ofMatrix4x4& getMatrix();
    
    void hide();
    void show();
    void toggleVisible();
    bool isVisible();
    
    // is the gizmo using the mouse?
    bool isInteracting();
    
    void setViewDimensions( float aw, float ah );
    
    string getMatrixAsString();
    bool save( string aFileName );
    bool load( string aFileName );
    
    void enableMouseInput();
    void disableMouseInput();
    
    void mouseMoved( ofMouseEventArgs& args );
    void mouseDragged( ofMouseEventArgs& args );
    void mousePressed( ofMouseEventArgs& args );
    void mouseReleased( ofMouseEventArgs& args );
    
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    bool mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
protected:
    bool _bHasMouseEvents;
    bool _bInteracting;
    bool _bVisible;
    float displayScale = 1;
    
    float _windowW, _windowH;
    bool bNodeSet;
    
    ofMatrix4x4 objectMatrix;
    IGizmo *gizmo       = NULL;
    IGizmo *gizmoMove   = NULL;
    IGizmo *gizmoRotate = NULL;
    IGizmo *gizmoScale  = NULL;
};
