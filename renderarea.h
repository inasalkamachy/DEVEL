#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>
#include <QPen>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType {Astroid, Cycloid, HuygensCycloid, HypoCycloid,Cycle,Ellips,Fancy,Starfish,Cloud,Cloud2, Line};
    //Shape Color
    void ShapeColor (QColor color){mPen.setColor(color); } // setter
    QColor ShapeColor () const {return mPen.color();} //getter
    //Background
    void setBackgroundColor (QColor color){mBackgroundColor = color; } // setter
    QColor backgroundColor () const {return mBackgroundColor;} //getter

    //set the shape here
    void setShape (ShapeType shape) {mShape = shape; on_shape_changed(); }
    ShapeType shape() const {return mShape;}

    //setScale
    void setScale(float scale) {mScale = scale; repaint ();}
    float scale () const {return mScale;}

    //set Interval Length
    void setLength(float length) {mIintervalLength = length; repaint ();}
    float length () const {return mIintervalLength;}

    //set setCount
    void setCount(int count) {mStepCount = count; repaint ();}
    float count () const {return mStepCount;}

  protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:
public slots:
private:
    void on_shape_changed();
    QPointF compute(float t);
    QPointF compute_astroid(float t);
    QPointF compute_Cycloid(float t);
    QPointF compute_HuygensCycloid(float t);
    QPointF compute_HypoCycloid(float t);
    QPointF compute_Ellips(float t);
    QPointF compute_Cycle(float t);
    QPointF compute_Fancy(float t);
    QPointF compute_Starfish(float t);
    QPointF compute_line(float t);
    QPointF compute_Cloud(float t);
    QPointF compute_Cloud2(float t);

private:
    QColor mBackgroundColor;
    QPen mPen;
    ShapeType mShape;
    float mIintervalLength;
    float mScale;
    int mStepCount;




};

#endif // RENDERAREA_H
