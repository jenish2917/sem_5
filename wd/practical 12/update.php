<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "EmployeeDB";

$conn = new mysqli($servername, $username, $password, $database);
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = $_POST['id'];
    $name = $_POST['name'];
    $department = $_POST['department'];
    $designation = $_POST['designation'];
    $sql = "UPDATE employees SET name=?, department=?, designation=? WHERE id=?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("sssi", $name, $department, $designation, $id);
    if ($stmt->execute()) {
        echo "Employee updated successfully.";
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
    <title>Update Employee</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
            margin-top: 50px;
        }
        form {
            display: inline-block;
            text-align: left;
        }
        label, input {
            display: block;
            margin: 10px 0;
        }
        input[type="submit"] {
            padding: 10px 20px;
        }
    </style>
</head>
<body>
    <h2>Update Employee</h2>
    <form method="post" action="">
        <label>ID:</label>
        <input type="number" name="id" required>
        <label>Name:</label>
        <input type="text" name="name" required>
        <label>Department:</label>
        <input type="text" name="department" required>
        <label>Designation:</label>
        <input type="text" name="designation" required>
        <input type="submit" value="Update">
    </form>
    <button onclick="window.location.href='index.php'">Back to Menu</button>
</body>
</html>
