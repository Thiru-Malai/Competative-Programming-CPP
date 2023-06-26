<?php
$A = 100;
$B = "200";
fun();

function fun(){
	$A = 200;
	echo  $GLOBALS['A'];
    echo "<br>";
    echo count($GLOBALS['A']);
    echo "<br>";
	$C = $A + count($GLOBALS['A']) + count($GLOBALS['B']);
	echo $C;
}
echo "I love $txt!";
?>