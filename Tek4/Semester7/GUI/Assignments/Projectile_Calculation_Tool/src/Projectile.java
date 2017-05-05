import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;

import java.text.DecimalFormat;
import java.util.regex.Pattern;

public class Projectile extends Application {
    // TODO : TODO's are used to show where Bonus are ! :-)
    //State
    private boolean fired = false;

    //Layout
    private BorderPane mainLayout;

    //Projectile Type
    private Label projectile_type_label = new Label("Projectile Type");
    private ComboBox<String> projectile_type_combobox = new ComboBox<>();

    // Mass
    private Label mass_label = new Label("Mass (kgs)");
    private TextField mass_textField = new TextField();
    private Label bonus_label = new Label("Bonus: You can only enter digits");

    //Angle
    private Label angle_label = new Label("Angle (degrees)");
    private TextField angle_textField = new TextField();
    private Slider angle_slider = new Slider();
    private double angle;

    //Formating the values in the duration box
    private DecimalFormat df;

    //Initial Speed
    private Label initial_speed_label = new Label("Initial Speed (m/s)");
    private ToggleGroup initial_speed_toggleGroup = new ToggleGroup();
    private RadioButton initial_speed_slow = new RadioButton("Slow");
    private RadioButton initial_speed_medium = new RadioButton("Medium");
    private RadioButton initial_speed_fast = new RadioButton("Fast");
    private TextField initial_speed_textField = new TextField();
    private double initial_speed;

    //Range
    private Label range_label = new Label("Range (m)");
    private TextField range_textField = new TextField();
    private double range;

    //Height
    private Label height_label = new Label("Max height (m)");
    private TextField height_textField = new TextField();
    private double height;

    //Time
    private Label time_label = new Label("Time (s)");
    private TextField time_textField = new TextField();
    private double time;

    //Calculate
    private Button fire_button = new Button("Fire");
    private Button erase_button = new Button("Erase");

    //Const Variables
    private static final double gravitational_acceleration = 9.81;

    public void init() {
        df = new DecimalFormat("###,###.##");

        projectile_type_combobox.getItems().addAll("Adult Human", "Piano");
        projectile_type_combobox.setValue("Adult Human");

        initial_speed_slow.setUserData("10");
        initial_speed_medium.setUserData("50");
        initial_speed_fast.setUserData("100");
        initial_speed_slow.setToggleGroup(initial_speed_toggleGroup);
        initial_speed_medium.setToggleGroup(initial_speed_toggleGroup);
        initial_speed_fast.setToggleGroup(initial_speed_toggleGroup);

        setValues(projectile_type_combobox.getValue());

        angle_textField.setDisable(true);
        initial_speed_textField.setDisable(true);
        range_textField.setDisable(true);
        height_textField.setDisable(true);
        time_textField.setDisable(true);

        setLayouts();

        /*
        ** TODO : Bonus, manage the only digits part
        */
        mass_textField.textProperty().addListener((observable, value, newValue) -> {
            if (newValue.equals(value))
                return;
            if (newValue.isEmpty()) {
                mass_textField.setText("0");
            } else if (!isNumeric(newValue)) {
                mass_textField.setText(value.charAt(0) == '0' ? "" : value);
            } else if (newValue.charAt(0) == '0' && newValue.length() > 1) {
                newValue = newValue.substring(1);
                mass_textField.setText(newValue);
            }
        });

        angle_slider.valueProperty().addListener((observable, oldValue, newValue) -> {
            angle = (double) newValue;
            angle_textField.setText(df.format(angle));
            if (fired)
                fire();
        });

        initial_speed_toggleGroup.selectedToggleProperty().addListener((ov, toggle, new_toggle) -> {
            initial_speed = Double.parseDouble(new_toggle.getUserData().toString());
            initial_speed_textField.setText(df.format(initial_speed));
            if (fired)
                fire();
        });

        projectile_type_combobox.setOnAction(event -> setValues(projectile_type_combobox.getValue()));

        fire_button.setOnAction(event -> fire());

        erase_button.setOnAction(event -> setValues(projectile_type_combobox.getValue()));
    }

    private void setValues(String projectileSelected) {
        if (projectileSelected.equals("Piano")) {
            mass_textField.setText("400");

            angle = 20;
            angle_slider.setMin(0);
            angle_slider.setMax(40);
            angle_slider.setValue(20);
            angle_slider.setMajorTickUnit(10);

            initial_speed = 10;
            initial_speed_toggleGroup.selectToggle(initial_speed_slow);
        } else {
            mass_textField.setText("80");

            angle = 45;
            angle_slider.setMin(0);
            angle_slider.setMax(90);
            angle_slider.setValue(45);
            angle_slider.setMajorTickUnit(15);

            initial_speed = 100;
            initial_speed_toggleGroup.selectToggle(initial_speed_fast);
        }
        angle_slider.setShowTickMarks(true);
        angle_slider.setShowTickLabels(true);
        clearUI();
    }

    private void setLayouts() {
        mainLayout = new BorderPane();
        mainLayout.setPadding(new Insets(20, 20, 50, 20));
        HBox layoutInputs = new HBox(30);
        HBox layoutResults = new HBox(30);
        HBox layoutButtons = new HBox(30);
        mainLayout.setTop(layoutInputs);
        mainLayout.setCenter(layoutResults);
        mainLayout.setBottom(layoutButtons);


        VBox projectileBox = new VBox(10);
        VBox massBox = new VBox(10);
        VBox angleBox = new VBox(10);
        VBox initSpeedBox = new VBox(10);
        layoutInputs.setAlignment(Pos.CENTER);
        layoutInputs.getChildren().addAll(projectileBox, massBox, angleBox, initSpeedBox);

        projectileBox.getChildren().addAll(projectile_type_label, projectile_type_combobox);
        massBox.getChildren().addAll(mass_label, mass_textField, bonus_label);
        mass_textField.setStyle("-fx-opacity: 1.0");
        mass_textField.setAlignment(Pos.CENTER);
        bonus_label.setFont(Font.font("Verdana", 11));
        bonus_label.setStyle("-fx-text-fill: #E53935");
        angleBox.getChildren().addAll(angle_label, angle_textField, angle_slider);
        angle_textField.setStyle("-fx-opacity: 1.0");
        angle_textField.setAlignment(Pos.CENTER);
        HBox toggleSpeeds = new HBox(10);
        initSpeedBox.getChildren().addAll(initial_speed_label, initial_speed_textField, toggleSpeeds);
        toggleSpeeds.getChildren().addAll(initial_speed_slow, initial_speed_medium, initial_speed_fast);
        initial_speed_textField.setStyle("-fx-opacity: 1.0");
        initial_speed_textField.setAlignment(Pos.CENTER);


        VBox rangeBox = new VBox(10);
        VBox heightBox = new VBox(10);
        VBox timeBox = new VBox(10);
        layoutResults.setAlignment(Pos.CENTER);
        layoutResults.getChildren().addAll(rangeBox, heightBox, timeBox);

        range_textField.setPrefHeight(100);
        range_textField.setFont(Font.font("Verdana", 35));
        range_textField.setStyle("-fx-text-fill: #E53935; -fx-opacity: 1.0");
        range_textField.setAlignment(Pos.CENTER);
        rangeBox.getChildren().addAll(range_label, range_textField);
        rangeBox.setAlignment(Pos.CENTER);
        height_textField.setPrefHeight(100);
        height_textField.setFont(Font.font("Verdana", 35));
        height_textField.setStyle("-fx-text-fill: #E53935; -fx-opacity: 1.0");
        height_textField.setAlignment(Pos.CENTER);
        heightBox.getChildren().addAll(height_label, height_textField);
        heightBox.setAlignment(Pos.CENTER);
        time_textField.setPrefHeight(100);
        time_textField.setFont(Font.font("Verdana", 35));
        time_textField.setStyle("-fx-text-fill: #E53935; -fx-opacity: 1.0");
        time_textField.setAlignment(Pos.CENTER);
        timeBox.getChildren().addAll(time_label, time_textField);
        timeBox.setAlignment(Pos.CENTER);


        layoutButtons.setAlignment(Pos.CENTER);
        layoutButtons.getChildren().addAll(fire_button, erase_button);
        fire_button.setPrefSize(200, 30);
        fire_button.setStyle("-fx-text-fill: white; -fx-effect: dropshadow(gaussian, rgba(0.0, 0.0, 0.0, 0.30), 6.0, 0.3, 0,1); -fx-background-color: rgb(76, 175, 80);");
        erase_button.setPrefSize(200, 30);
        erase_button.setStyle("-fx-text-fill: white; -fx-effect: dropshadow(gaussian, rgba(0.0, 0.0, 0.0, 0.30), 6.0, 0.3, 0,1); -fx-background-color: rgb(244, 67, 54);");
    }

    private void fire() {
        Double radian = angle * (Math.PI / 180);

        range = (Math.pow(initial_speed, 2.0) / gravitational_acceleration) * Math.sin(2 * radian);
        range_textField.setText(df.format(range));

        height = Math.pow(initial_speed, 2.0) * Math.pow(Math.sin(radian), 2.0) / (2 * gravitational_acceleration);
        height_textField.setText(df.format(height));

        time = ((2 * initial_speed) * Math.sin(radian)) / gravitational_acceleration;
        time_textField.setText(df.format(time));

        fired = true;
    }

    private void clearUI() {
        range = 0;
        height = 0;
        time = 0;
        range_textField.clear();
        height_textField.clear();
        time_textField.clear();

        angle_textField.setText(df.format(angle));
        initial_speed_textField.setText(df.format(initial_speed));

        fired = false;
    }

    private boolean isNumeric(String nbr) {
       return Pattern.matches("[0-9]+", nbr);
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Fire in the hole !!!");
        primaryStage.setScene(new Scene(mainLayout, 900, 500));
        // TODO : Bonus, prevent user from resizing to a non usable application
        primaryStage.setMinWidth(900);
        primaryStage.setMinHeight(500);
        primaryStage.show();
    }

    public void stop() {

    }

    public static void main(String[] args) {
        launch(args);
    }
}

