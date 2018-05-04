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
}

// get the most recent color entry in the database table.
$sql = "SELECT * FROM distanceData";
$result = mysqli_query($conn, $sql);
//echo"hi";
// list the query result rows in a CSV format.
while($row = mysqli_fetch_array($result)){
  echo  $row[1] . "," . $row[2] . "\n";
}

 ?>
