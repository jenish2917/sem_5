<!DOCTYPE html>
<html>
<head>
    <title>User Input Form</title>
</head>
<body>
    <h2>User Input Form</h2>
    <form method="post" action="">
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required><br><br>

        <label>Gender:</label>
        <input type="radio" id="male" name="gender" value="Male" required>
        <label for="male">Male</label>
        <input type="radio" id="female" name="gender" value="Female">
        <label for="female">Female</label><br><br>

        <label for="hobbies">Hobbies:</label>
        <input type="checkbox" id="hobby1" name="hobbies[]" value="Reading">
        <label for="hobby1">Reading</label>
        <input type="checkbox" id="hobby2" name="hobbies[]" value="Traveling">
        <label for="hobby2">Traveling</label>
        <input type="checkbox" id="hobby3" name="hobbies[]" value="Gaming">
        <label for="hobby3">Gaming</label><br><br>

        <label for="country">Country:</label>
        <select id="country" name="country">
            <option value="USA">USA</option>
            <option value="Canada">Canada</option>
            <option value="UK">UK</option>
            <option value="Australia">Australia</option>
        </select><br><br>

        <input type="submit" value="Submit">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = htmlspecialchars($_POST["name"]);
        $gender = htmlspecialchars($_POST["gender"]);
        $hobbies = isset($_POST["hobbies"]) ? htmlspecialchars(implode(", ", $_POST["hobbies"])) : "None";
        $country = htmlspecialchars($_POST["country"]);

        echo "<h3>User Input Summary</h3>";
        echo "<p>Name: $name</p>";
        echo "<p>Gender: $gender</p>";
        echo "<p>Hobbies: $hobbies</p>";
        echo "<p>Country: $country</p>";
    }
    ?>
</body>
</html>
