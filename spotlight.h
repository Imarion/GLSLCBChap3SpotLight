#include <QWindow>
#include <QTimer>
#include <QString>
#include <QKeyEvent>

#include <QVector3D>
#include <QMatrix4x4>

#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_4_3_Core>

#include <QOpenGLShaderProgram>

#include "teapot.h"
#include "vboplane.h"
#include "torus.h"

#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)
#define TwoPI (float)(2 * M_PI)

//class MyWindow : public QWindow, protected QOpenGLFunctions_3_3_Core
class MyWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit MyWindow();
    ~MyWindow();
    virtual void keyPressEvent( QKeyEvent *keyEvent );    

private slots:
    void render();

private:    
    void initialize();
    void modCurTime();

    void initShaders();
    void CreateVertexBuffer();    
    void initMatrices();

    void PrepareTexture(GLenum TextureTarget, const QString& FileName, GLuint& TexObject, bool flip);

protected:
    void resizeEvent(QResizeEvent *);

private:
    QOpenGLContext *mContext;
    QOpenGLFunctions_4_3_Core *mFuncs;

    QOpenGLShaderProgram *mProgram;

    QTimer mRepaintTimer;
    double currentTimeMs;
    double currentTimeS;
    bool   mUpdateSize;
    float  tPrev, angle;

    GLuint mVAOTeapot, mVAOPlane, mVAOTorus, mVBO, mIBO;
    GLuint mPositionBufferHandle, mColorBufferHandle;
    GLuint mRotationMatrixLocation;

    Teapot   *mTeapot;
    VBOPlane *mPlane;
    Torus    *mTorus;

    QMatrix4x4 ModelMatrixTeapot, ModelMatrixPlane, ModelMatrixTorus, ViewMatrix, ProjectionMatrix;

    //debug
    void printMatrix(const QMatrix4x4& mat);
};
