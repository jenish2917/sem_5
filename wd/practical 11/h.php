<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "StudentDB";

$conn = new mysqli($servername, $username, $password, $database);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT * FROM student WHERE marks >= 35";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    echo "<h2>Students with Marks >= 35:</h2>";
    echo "<table border='1'><tr><th>Enroll No</th><th>Name</th><th>Age</th><th>Marks</th></tr>";
    
    while ($row = $result->fetch_assoc()) {
        echo "<tr><td>" . $row["Enroll_no"] . "</td><td>" . $row["name"] . "</td><td>" . $row["age"] . "</td><td>" . $row["marks"] . "</td></tr>";
    }
    
    echo "</table>";
} else {
    echo "No records found.";
}

$conn->close();
?>
