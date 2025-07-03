<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "esp_data";

$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
    die("DB connection failed: " . $conn->connect_error);
}

if (isset($_GET['temp']) && isset($_GET['hum'])) {
    $temp = $_GET['temp'];
    $hum = $_GET['hum'];
    $sql = "INSERT INTO dht_data (temperature, humidity) VALUES ('$temp', '$hum')";
    if ($conn->query($sql) === TRUE) {
        echo "Data saved: T=$temp H=$hum";
    } else {
        echo "DB Error: " . $conn->error;
    }
} else {
    echo "Missing parameters.";
}

$conn->close();
?>
