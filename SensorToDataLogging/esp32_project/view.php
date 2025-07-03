<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "esp_data";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT id, temperature, humidity, reading_time FROM dht_data ORDER BY id DESC LIMIT 20";
$result = $conn->query($sql);

echo "<!DOCTYPE html>
<html>
<head >
<title>ESP32 Sensor Data</title>
<style>
  body { font-family: Arial; background: #f8f8f8; text-align: center; }
  table { border-collapse: collapse; margin: 20px auto; width: 80%; }
  th, td { padding: 8px 12px; border: 1px solid #ddd; }
  th { background: #333; color: white; }
  tr:nth-child(even) { background: #eee; }
</style>
</head>
<body>
<h2>ESP32 Sensor Data (Last 20 Readings)</h2>
<table>
<tr><th>ID</th><th>Temperature</th><th>Humidity</th><th>Timestamp</th></tr>";

if ($result->num_rows > 0) {
  while($row = $result->fetch_assoc()) {
    echo "<tr><td>".$row["id"]."</td><td>".$row["temperature"]."</td><td>".$row["humidity"]."</td><td>".$row["reading_time"]."</td></tr>";
  }
} else {
  echo "<tr><td colspan='4'>No data found</td></tr>";
}

echo "</table>
</body></html>";

$conn->close();
?>
