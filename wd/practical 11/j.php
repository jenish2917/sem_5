<?php
$servername = "localhost";
$username = "root";
$password = "";

$conn = new mysqli($servername, $username, $password);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "DROP TABLE IF EXISTS StudentDB.student";
if ($conn->query($sql) === TRUE) {
    echo "Table 'student' dropped successfully.<br>";
} else {
    echo "Error dropping table: " . $conn->error . "<br>";
}

$sql = "DROP DATABASE IF EXISTS StudentDB";
if ($conn->query($sql) === TRUE) {
    echo "Database 'StudentDB' dropped successfully.";
} else {
    echo "Error dropping database: " . $conn->error;
}

$conn->close();
?>
