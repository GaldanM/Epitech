import javafx.scene.control.Control;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.StrokeType;

class Cell extends Control {

    private Board board;
    int y;
    int z1;
    int z2;
    int x;
    int type;
    int stroke;

    private int originalType;

    private Ellipse circle;

    private final Paint[] typeColors = {
            Paint.valueOf("#757575"),
            Paint.valueOf("#FFFFFF"),
            Paint.valueOf("#000000")
    };

    private final Paint[] typeStrokes = {
            Color.TRANSPARENT,
            Paint.valueOf("#4CAF50"),
            Paint.valueOf("#FFC107"),
            Paint.valueOf("#2196F3"),
            Paint.valueOf("#F44336")
    };

    Cell(Board board, int y, int x, int z1, int z2, int type, int stroke) {
        this.setSkin(new CellSkin(this));
        this.board = board;
        this.y = y;
        this.x = x;
        this.z1 = z1;
        this.z2 = z2;
        this.type = type;
        this.originalType = type;
        this.stroke = stroke;

        this.circle = new Ellipse();
        this.circle.setFill(this.typeColors[type]);
        this.circle.setStrokeType(StrokeType.INSIDE);
        this.circle.setStrokeWidth(5);
        getChildren().add(this.circle);

        setOnMouseClicked(event -> this.board.pieceClicked(this.y, this.x));
    }

    void setType(int type) {
        this.circle.setFill(this.typeColors[type]);
        this.type = type;
    }

    void setStroke(int stroke) {
        this.circle.setStroke(typeStrokes[stroke]);
        this.stroke = stroke;
    }

    void reset() {
        this.setType(this.originalType);
        this.setStroke(0);
    }

    @Override
    public void resize(double width, double height) {
        super.resize(width, height);
        this.circle.setCenterX(28);
        this.circle.setCenterY(28);
        this.circle.setRadiusX(28);
        this.circle.setRadiusY(28);
    }
}
