package JavaFXbyExample.Ex20;

import javafx.scene.control.Alert;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.transform.Translate;

class XOBoard extends Pane {
    private int[][] board;
    private XOPiece[][] renders;
    private Rectangle back;
    private Line h1, h2, v1, v2;
    private double cell_width, cell_height;

    private Translate ch_one, ch_two, cw_one, cw_two;
    private int current_player;
    private int move_count = 0;

    private final int EMPTY = 0;
    private final int XPIECE = 1;
    private final int OPIECE = 2;

    public XOBoard() {
        board = new int[3][3];
        renders = new XOPiece[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                board[i][j] = EMPTY;
                renders[i][j] = null;
            }
        current_player = XPIECE;

        back = new Rectangle();
        back.setFill(Color.WHITE);
        h1 = new Line(); h2 = new Line();
        v1 = new Line(); v2 = new Line();
        h1.setStroke(Color.BLACK); h2.setStroke(Color.BLACK);
        v1.setStroke(Color.BLACK); v2.setStroke(Color.BLACK);

        h1.setStartX(0); h1.setStartY(0); h1.setEndY(0);
        h2.setStartX(0); h2.setStartY(0); h2.setEndY(0);
        v1.setStartX(0); v1.setStartY(0); v1.setEndX(0);
        v2.setStartX(0); v2.setStartY(0); v2.setEndX(0);

        ch_one = new Translate(0, 0);
        ch_two = new Translate(0, 0);
        h1.getTransforms().add(ch_one);
        h2.getTransforms().add(ch_two);

        cw_one = new Translate(0, 0);
        cw_two = new Translate(0, 0);
        v1.getTransforms().add(cw_one);
        v2.getTransforms().add(cw_two);

        getChildren().addAll(back, h1, h2, v1, v2);
    }

    @Override
    public void resize(double width, double height) {
        super.resize(width, height);
        cell_width = width / 3.0;
        cell_height = height / 3.0;

        back.setWidth(width);
        back.setHeight(height);

        ch_one.setY(cell_height);
        ch_two.setY(2 * cell_height);
        h1.setEndX(width);
        h2.setEndX(width);

        cw_one.setX(cell_width);
        cw_two.setX(2 * cell_width);
        v1.setEndY(height);
        v2.setEndY(height);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] != 0) {
                    renders[i][j].relocate(i * cell_width, j * cell_height);
                    renders[i][j].resize(cell_width, cell_height);
                }
            }
        }
    }

    public void resetGame() {
        move_count = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                board[i][j] = 0;
                getChildren().remove(renders[i][j]);
                renders[i][j] = null;
            }
        }
    }

    public void placePiece(final double x, final double y) {
        int indexX = (int) (x / cell_width);
        int indexY = (int) (y / cell_height);

        if (board[indexX][indexY] == EMPTY && current_player == XPIECE) {
            board[indexX][indexY] = XPIECE;
            renders[indexX][indexY] = new XOPiece(XPIECE);
            renders[indexX][indexY].resize(cell_width, cell_height);
            renders[indexX][indexY].relocate(indexX * cell_width, indexY * cell_height);
            getChildren().add(renders[indexX][indexY]);
            current_player = OPIECE;
        } else if(board[indexX][indexY] == EMPTY && current_player == OPIECE) {
            board[indexX][indexY] = OPIECE;
            renders[indexX][indexY] = new XOPiece(OPIECE);
            renders[indexX][indexY].resize(cell_width, cell_height);
            renders[indexX][indexY].relocate(indexX * cell_width, indexY *
                    cell_height);
            getChildren().add(renders[indexX][indexY]);
            current_player = XPIECE;
        }
        ++move_count;
        checkWin(indexX, indexY, board[indexX][indexY]);
    }

    public void checkWin(final int x, final int y, final int s) {
        int n = 3;

        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("You Win !!");
        String piece = s == 1 ? "Crosses" : "Circles";
        alert.setHeaderText(piece + " has won this game !");
        alert.showAndWait();

        for(int i = 0; i < n; i++){
            if(board[x][i] != s)
                break;
            if(i == n - 1) {
                alert.showAndWait();
                resetGame();
            }
        }

        for(int i = 0; i < n; i++){
            if(board[i][y] != s)
                break;
            if(i == n-1){
                alert.showAndWait();
                resetGame();
            }
        }

        if(x == y){
            for(int i = 0; i < n; i++){
                if(board[i][i] != s)
                    break;
                if(i == n-1){
                    alert.showAndWait();
                    resetGame();
                }
            }
        }

        for(int i = 0;i<n;i++){
            if(board[i][(n-1)-i] != s)
                break;
            if(i == n-1){
                alert.showAndWait();
                resetGame();
            }
        }

        if(this.move_count == 9){
            alert.setTitle("Draw");
            alert.setHeaderText("Noboy won this game, try again !");
            alert.showAndWait();
            resetGame();
        }
    }
}
