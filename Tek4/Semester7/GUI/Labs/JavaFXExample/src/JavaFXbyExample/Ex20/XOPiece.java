package JavaFXbyExample.Ex20;

import javafx.scene.Group;
import javafx.scene.paint.Color;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.scene.transform.Translate;

class XOPiece extends Group {

    private Line l1, l2;
    private Ellipse e;
    private int type;
    private Translate pos;

    public XOPiece(int type) {
        pos = new Translate();
        this.type = type;

        if (type == 1) {
            l1 = new Line(); l2 = new Line();
            getChildren().addAll(l1, l2);
            l1.getTransforms().add(pos); l2.getTransforms().add(pos);
            l1.setStroke(Color.RED); l2.setStroke(Color.RED);

            l1.setStartX(0); l1.setStartY(0);
            l2.setStartY(0); l2.setEndX(0);
        } else {
            e = new Ellipse();
            getChildren().addAll(e);
            e.getTransforms().add(pos);
            e.setStroke(Color.LIME);
            e.setFill(Color.WHITE);
        }
    }

    @Override
    public void resize(double width, double height) {
        super.resize(width, height);
        if(type == 1) {
            l1.setEndX(width); l1.setEndY(height);
            l2.setStartX(width); l2.setEndY(height);
        } else {
            e.setCenterX(width / 2); e.setCenterY(height / 2);
            e.setRadiusX(width / 2); e.setRadiusY(height / 2);
        }
    }

    @Override
    public void relocate(double x, double y) {
        super.relocate(x, y);
        pos.setX(x); pos.setY(y);
    }
}
