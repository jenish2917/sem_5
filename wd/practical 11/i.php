<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "StudentDB";

$conn = new mysqli($servername, $username, $password, $database);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$new_age = 31; 
$new_marks = 40;

$sql = "UPDATE student SET age = ?, marks = ? WHERE age = 30";
$stmt = $conn->prepare($sql);
$stmt->bind_param("id", $new_age, $new_marks);

if ($stmt->execute()) {
    echo "Records updated successfully.";
} else {
    echo "Error updating records: " . $stmt->error;
}

$stmt->close();
$conn->close();
?>
