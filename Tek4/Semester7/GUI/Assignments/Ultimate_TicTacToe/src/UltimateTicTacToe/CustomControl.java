package UltimateTicTacToe;

import javafx.scene.control.Control;
import javafx.scene.input.KeyCode;

class CustomControl extends Control {
    private XOMainBoard ultimateMainBoard;

    CustomControl() {
        setSkin(new CustomControlSkin(this));
        ultimateMainBoard = new XOMainBoard();
        getChildren().add(ultimateMainBoard);

        setOnMouseClicked(event -> ultimateMainBoard.placePiece(event.getX(), event.getY()));
        setOnKeyPressed(event -> {
            if (event.getCode() == KeyCode.SPACE) {
                ultimateMainBoard.resetGame();
            }
        });
    }

    @Override
    public void resize(double width, double height) {
        super.resize(width, height);
        ultimateMainBoard.resize(width, height);
    }
}
