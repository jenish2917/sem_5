<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "StudentDB";

$conn = new mysqli($servername, $username, $password, $database);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $enroll_no = $_POST['enroll_no'];
    $name = $_POST['name'];
    $age = $_POST['age'];
    $marks = $_POST['marks'];

    $sql = "INSERT INTO student (Enroll_no, name, age, marks) VALUES (?, ?, ?, ?)";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("isid", $enroll_no, $name, $age, $marks);

    if ($stmt->execute()) {
        echo "New record inserted successfully.";
    } else {
        echo "Error: " . $stmt->error;
    }

    $stmt->close();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Insert Student</title>
</head>
<body>
    <h2>Insert Student Record</h2>
    <form method="post" action="">
        <label for="enroll_no">Enroll No:</label>
        <input type="number" id="enroll_no" name="enroll_no" required><br><br>
        
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required><br><br>
        
        <label for="age">Age:</label>
        <input type="number" id="age" name="age" required><br><br>
        
        <label for="marks">Marks:</label>
        <input type="number" step="0.01" id="marks" name="marks" required><br><br>
        
        <input type="submit" value="Insert Student">
    </form>
</body>
</html>
