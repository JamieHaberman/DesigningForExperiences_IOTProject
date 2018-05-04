<?php

// turn error reporting on to see where things go wrong.
error_reporting(-1);

// login with your database credentials.
$servername = "localhost";
$username = "nnagda";
$password = "1234";
$dbname = "iotProject";

// connect to the database with the information above.
$conn = mysqli_connect($servername, $username, $password, $dbname);
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
    print("no");
}
else{
    print("yes");
}

// make sure red, green, and blue values have been passed in.
if(isset($_GET["distance"])){
  // clean and store the color values.
  $distance = mysqli_real_escape_string($conn, htmlspecialchars($_GET["distance"]));


  // insert color values into database table.
  $sql = "INSERT INTO distanceData (Distance) VALUES ('{$distance}')";
  // we don't use the result in this case, but must execute the query.
  $result = mysqli_query($conn, $sql);
}

?>
