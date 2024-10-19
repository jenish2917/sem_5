<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "StudentDB";

$conn = new mysqli($servername, $username, $password, $database);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "DELETE FROM student WHERE Enroll_no BETWEEN 1 AND 3";

if ($conn->query($sql) === TRUE) {
    echo "Records deleted successfully.";
} else {
    echo "Error deleting records: " . $conn->error;
}

$conn->close();
?>
