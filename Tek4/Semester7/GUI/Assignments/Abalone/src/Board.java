import javafx.geometry.Pos;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Polygon;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;

class Board extends VBox {
    // ATTRIBUTES TO MANAGE THE GAME
    Cell[][] cells;
    private GameLogic logic;

    // POLYGON THAT REPRESENTS THE BOARD
    private Polygon polygon;

    // TYPES OF A CELL
    private final int EMPTY = 0;
    private final int WHITE = 1;
    private final int BLACK = 2;
    private final int OUT = 3;

    // ACTIONS OF A CELL
    private final int NOTHING = 0;
    private final int SELECTED = 1;
    private final int SELECTABLE = 2;
    private final int MOVABLE = 3;
    private final int ATTACKABLE = 4;

    // TEXT TO INDICATE GAME STATUS
    private Text turnBlack;
    private Text remainBlackText;
    private Text remainBlack;
    private Text lostBlackText;
    private Text lostBlack;

    private Text turnWhite;
    private Text remainWhiteText;
    private Text remainWhite;
    private Text lostWhiteText;
    private Text lostWhite;

    Board() {
        this.setSpacing(20);
        this.initScore();
        this.initBoard();

        logic = new GameLogic(this);
        this.setNextPlayer(logic.getCurrentPlayer());
    }

    private void initScore() {
        BorderPane score = new BorderPane();

        HBox hBoxW = new HBox();
        hBoxW.setSpacing(30);
        HBox hBoxRW = new HBox();
        this.remainWhiteText = new Text("REMAIN : ");
        this.remainWhite = new Text("14");
        this.remainWhiteText.setFont(Font.font("Verdana", FontWeight.BOLD, 20));
        this.remainWhite.setFont(Font.font("Verdana", FontWeight.BOLD, 20));
        this.remainWhiteText.setFill(Color.WHITE);
        this.remainWhite.setFill(Color.WHITE);
        hBoxRW.getChildren().addAll(this.remainWhiteText, this.remainWhite);
        HBox hBoxLW = new HBox();
        this.lostWhiteText = new Text("LOST : ");
        this.lostWhite = new Text("0");
        this.lostWhiteText.setFont(Font.font("Verdana", FontWeight.BOLD, 20));
        this.lostWhite.setFont(Font.font("Verdana", FontWeight.BOLD, 20));
        this.lostWhiteText.setFill(Color.WHITE);
        this.lostWhite.setFill(Color.WHITE);
        hBoxLW.getChildren().addAll(this.lostWhiteText, this.lostWhite);
        hBoxW.getChildren().addAll(hBoxRW, hBoxLW);
        score.setLeft(hBoxW);

        HBox hBoxB = new HBox();
        hBoxB.setSpacing(30);
        HBox hBoxRB = new HBox();
        this.remainBlackText = new Text("REMAIN : ");
        this.remainBlack = new Text("14");
        this.remainBlackText.setFont(Font.font("Verdana", FontWeight.BOLD, 20));
        this.remainBlack.setFont(Font.font("Verdana", FontWeight.BOLD, 20));
        this.remainBlackText.setFill(Color.BLACK);
        this.remainBlack.setFill(Color.BLACK);
        hBoxRB.getChildren().addAll(this.remainBlackText, this.remainBlack);
        HBox hBoxLB = new HBox();
        this.lostBlackText = new Text("LOST : ");
        this.lostBlack = new Text("0");
        this.lostBlackText.setFont(Font.font("Verdana", FontWeight.BOLD, 20));
        this.lostBlack.setFont(Font.font("Verdana", FontWeight.BOLD, 20));
        this.lostBlackText.setFill(Color.BLACK);
        this.lostBlack.setFill(Color.BLACK);
        hBoxLB.getChildren().addAll(this.lostBlackText, this.lostBlack);
        hBoxB.getChildren().addAll(hBoxRB, hBoxLB);
        score.setRight(hBoxB);

        this.getChildren().add(score);
    }

    private void initBoard() {
        BorderPane boardPane = new BorderPane();

        this.turnBlack = new Text("BLACK TURN");
        this.turnWhite = new Text("WHITE TURN");
        this.turnBlack.setFont(Font.font("Verdana", FontWeight.BOLD, 42));
        this.turnWhite.setFont(Font.font("Verdana", FontWeight.BOLD, 42));
        boardPane.setBottom(this.turnBlack);
        boardPane.setTop(this.turnWhite);
        BorderPane.setAlignment(boardPane.getBottom(), Pos.BOTTOM_CENTER);
        BorderPane.setAlignment(boardPane.getTop(), Pos.TOP_CENTER);

        StackPane center = new StackPane();

        polygon = new Polygon();
        polygon.getPoints().addAll(makeVertices());
        polygon.setFill(Paint.valueOf("#BDBDBD"));
        this.setShape(polygon);
        center.getChildren().add(polygon);

        cells = new Cell[][]{
                {new Cell(this, 0, 0, 5, 1, WHITE, NOTHING), new Cell(this, 0, 1, 6, 2, WHITE, NOTHING), new Cell(this, 0, 2, 7, 3, WHITE, NOTHING), new Cell(this, 0, 3, 8, 4, WHITE, NOTHING), new Cell(this, 0, 4, 9, 5, WHITE, NOTHING)},
                {new Cell(this, 1, 0, 4, 1, WHITE, NOTHING), new Cell(this, 1, 1, 5, 2, WHITE, NOTHING), new Cell(this, 1, 2, 6, 3, WHITE, NOTHING), new Cell(this, 1, 3, 7, 4, WHITE, NOTHING), new Cell(this, 1, 4, 8, 5, WHITE, NOTHING), new Cell(this, 1, 5, 9, 6, WHITE, NOTHING)},
                {new Cell(this, 2, 0, 3, 1, EMPTY, NOTHING), new Cell(this, 2, 1, 4, 2, EMPTY, NOTHING), new Cell(this, 2, 2, 5, 3, WHITE, NOTHING), new Cell(this, 2, 3, 6, 4, WHITE, NOTHING), new Cell(this, 2, 4, 7, 5, WHITE, NOTHING), new Cell(this, 2, 5, 8, 6, EMPTY, NOTHING), new Cell(this, 2, 6, 9, 7, EMPTY, NOTHING)},
                {new Cell(this, 3, 0, 2, 1, EMPTY, NOTHING), new Cell(this, 3, 1, 3, 2, EMPTY, NOTHING), new Cell(this, 3, 2, 4, 3, EMPTY, NOTHING), new Cell(this, 3, 3, 5, 4, EMPTY, NOTHING), new Cell(this, 3, 4, 6, 5, EMPTY, NOTHING), new Cell(this, 3, 5, 7, 6, EMPTY, NOTHING), new Cell(this, 3, 6, 8, 7, EMPTY, NOTHING), new Cell(this, 3, 7, 9, 8, EMPTY, NOTHING)},
                {new Cell(this, 4, 0, 1, 1, EMPTY, NOTHING), new Cell(this, 4, 1, 2, 2, EMPTY, NOTHING), new Cell(this, 4, 2, 3, 3, EMPTY, NOTHING), new Cell(this, 4, 3, 4, 4, EMPTY, NOTHING), new Cell(this, 4, 4, 5, 5, EMPTY, NOTHING), new Cell(this, 4, 5, 6, 6, EMPTY, NOTHING), new Cell(this, 4, 6, 7, 7, EMPTY, NOTHING), new Cell(this, 4, 7, 8, 8, EMPTY, NOTHING), new Cell(this, 4, 8, 9, 9, EMPTY, NOTHING)},
                {new Cell(this, 5, 0, 1, 2, EMPTY, NOTHING), new Cell(this, 5, 1, 2, 3, EMPTY, NOTHING), new Cell(this, 5, 2, 3, 4, EMPTY, NOTHING), new Cell(this, 5, 3, 4, 5, EMPTY, NOTHING), new Cell(this, 5, 4, 5, 6, EMPTY, NOTHING), new Cell(this, 5, 5, 6, 7, EMPTY, NOTHING), new Cell(this, 5, 6, 7, 8, EMPTY, NOTHING), new Cell(this, 5, 7, 8, 9, EMPTY, NOTHING)},
                {new Cell(this, 6, 0, 1, 3, EMPTY, NOTHING), new Cell(this, 6, 1, 2, 4, EMPTY, NOTHING), new Cell(this, 6, 2, 3, 5, BLACK, NOTHING), new Cell(this, 6, 3, 4, 6, BLACK, NOTHING), new Cell(this, 6, 4, 5, 7, BLACK, NOTHING), new Cell(this, 6, 5, 6, 8, EMPTY, NOTHING), new Cell(this, 6, 6, 7, 9, EMPTY, NOTHING)},
                {new Cell(this, 7, 0, 1, 4, BLACK, NOTHING), new Cell(this, 7, 1, 2, 5, BLACK, NOTHING), new Cell(this, 7, 2, 3, 6, BLACK, NOTHING), new Cell(this, 7, 3, 4, 7, BLACK, NOTHING), new Cell(this, 7, 4, 5, 8, BLACK, NOTHING), new Cell(this, 7, 5, 6, 9, BLACK, NOTHING)},
                {new Cell(this, 8, 0, 1, 5, BLACK, NOTHING), new Cell(this, 8, 1, 2, 6, BLACK, NOTHING), new Cell(this, 8, 2, 3, 7, BLACK, NOTHING), new Cell(this, 8, 3, 4, 8, BLACK, NOTHING), new Cell(this, 8, 4, 5, 9, BLACK, NOTHING)},
        };

        VBox rows = new VBox(0);
        rows.setAlignment(Pos.CENTER);
        for (Cell[] cellRow : cells) {
            HBox row = new HBox(10);
            row.setAlignment(Pos.CENTER);
            for (Cell cell : cellRow)
                row.getChildren().add(cell);
            rows.getChildren().add(row);
        }
        center.getChildren().add(rows);

        boardPane.setCenter(center);

        this.getChildren().add(boardPane);
    }

    private Double[] makeVertices() {
        int sides = 6;
        int radius = 300;
        Double[] vertices = new Double[sides * 2];
        int indexInVerticesArray = 0;

        for (int i = 1; i <= sides; i++) {
            vertices[indexInVerticesArray++] = radius * Math.cos((2 * Math.PI * i) / sides);
            vertices[indexInVerticesArray++] = radius * Math.sin((2 * Math.PI * i) / sides);
        }

        return vertices;
    }

    void updateScores() {
        this.remainWhite.setText(Integer.toString(logic.scores[WHITE]));
        this.lostWhite.setText(Integer.toString(14 - logic.scores[WHITE]));
        this.remainBlack.setText(Integer.toString(logic.scores[BLACK]));
        this.lostBlack.setText(Integer.toString(14 - logic.scores[BLACK]));
    }

    void pieceClicked(int y, int x) {
        logic.currentMove(y, x);
    }

    void setNextPlayer(int nextPlayer) {
        if (nextPlayer == BLACK) {
            this.turnBlack.setFill(Color.BLACK);
            this.turnWhite.setFill(Color.TRANSPARENT);
        } else {
            this.turnWhite.setFill(Color.WHITE);
            this.turnBlack.setFill(Color.TRANSPARENT);
        }
    }

    void reset() {
        this.logic.reset();
        for (Cell[] cellRow : cells) {
            for (Cell cell : cellRow) {
                cell.reset();
            }
        }
        this.updateScores();
    }

    Cell getCellFromZ1(int y, int z) {
        for (Cell[] cellRow : cells) {
            for (Cell cell : cellRow) {
                if (cell.y == y && cell.z1 == z)
                    return cell;
            }
        }
        return null;
    }

    Cell getCellFromZ2(int y, int z) {
        for (Cell[] cellRow : cells) {
            for (Cell cell : cellRow) {
                if (cell.y == y && cell.z2 == z)
                    return cell;
            }
        }
        return null;
    }

    @Override
    public void resize(double width, double height) {
        super.resize(width, height);
        this.polygon.resize(width, height);
        for (Cell[] cellRow : cells) {
            for (Cell cell : cellRow) {
                cell.resize(width, height);
            }
        }
    }
}