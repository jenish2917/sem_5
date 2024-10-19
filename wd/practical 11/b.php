<?php
$servername = "localhost";
$username = "root";
$password = "";

$conn = new mysqli($servername, $username, $password);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SHOW DATABASES";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "<h2>Available Databases:</h2><ul>";
    while ($row = $result->fetch_assoc()) {
        echo "<li>" . $row["Database"] . "</li>";
    }
    echo "</ul>";
} else {
    echo "No databases found.";
}

$conn->close();
?>
