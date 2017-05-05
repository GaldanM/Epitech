package JavaFXbyExample;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;


public class Ex10 extends Application {
    private Label label_username, label_password, label_ulabel, label_plabel;
    private TextField tf_username;
    private PasswordField pf_password;
    private GridPane gp_userpass;

    public void init() {
        label_username = new Label("No Username");
        label_password = new Label("No Password");
        label_ulabel = new Label("Username");
        label_plabel = new Label("Password");
        tf_username = new TextField();
        pf_password = new PasswordField();
        gp_userpass = new GridPane();

        gp_userpass.add(label_ulabel, 0, 0);
        gp_userpass.add(label_plabel, 0, 1);
        gp_userpass.add(tf_username, 1, 0);
        gp_userpass.add(pf_password, 1, 1);
        GridPane.setHgrow(tf_username, Priority.ALWAYS);
        GridPane.setHgrow(pf_password, Priority.ALWAYS);
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Melchior FTW");
        VBox vb = new VBox();
        primaryStage.setScene(new Scene(vb, 400, 300));

        primaryStage.show();

        vb.getChildren().addAll(label_username, label_password, gp_userpass);

        tf_username.setOnAction(event -> label_username.setText("Username is: " + tf_username.getText()));
        pf_password.setOnAction(event -> label_password.setText("Password is: " + pf_password.getText()));
    }

    @Override
    public void stop() {
    }

    public static void main(String[] args) {
        launch(args);
    }
}
