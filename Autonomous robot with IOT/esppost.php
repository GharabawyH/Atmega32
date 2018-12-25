<?php

 $var1 = $_POST['Temperature'];
 $var2 = $_POST['Pressure'];
 $var3 = $_POST['Altitude'];
 $var4 = $_POST['Humidity'];
 
 $FileContent = "This project is made by MTE LVL 400 Students.\n\nTemperature = ".$var1."\nPressure = ".$var2."\nAltitude = ".$var3."\nHumidity = ".$var4."\n";
 
 
 $Status = file_put_contents('sensor.txt',$FileContent);
 if($Status != false)
 {
	 echo "Success";
 }
 else
 {
	 echo "Fail";
 }

?>

