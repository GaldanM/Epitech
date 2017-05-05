package JavaFXbyExample.Ex20;

import javafx.scene.control.Control;
import javafx.scene.input.KeyCode;

class CustomControl extends Control {
    private XOBoard xoboard;

    public CustomControl() {
        setSkin(new CustomControlSkin(this));
        xoboard = new XOBoard();
        getChildren().add(xoboard);

        setOnMouseClicked(event -> xoboard.placePiece(event.getX(), event.getY()));
        setOnKeyPressed(event -> {
            if (event.getCode() == KeyCode.SPACE) {
                xoboard.resetGame();
            }
        });
    }

    @Override
    public void resize(double width, double height) {
        super.resize(width, height);
        xoboard.resize(width, height);
    }
}
