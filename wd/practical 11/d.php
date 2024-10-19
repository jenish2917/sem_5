<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "StudentDB";

$conn = new mysqli($servername, $username, $password, $database);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "CREATE TABLE student (
    Enroll_no INT(11) PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    age INT(3) NOT NULL,
    marks DECIMAL(5, 2) NOT NULL
)";

if ($conn->query($sql) === TRUE) {
    echo "Table 'student' created successfully.";
} else {
    echo "Error creating table: " . $conn->error;
}

$conn->close();
?>
