#!/usr/bin/php
<?php
#  zenox /usr/local/bin/php
/* * * *
 * * server.php
 * * relay.SwissaplS.ws/chat/
 * *
 * * version 20091023_193730 (CC) Luke JZ aka SwissalpS
 * * * */
error_reporting(E_ALL); // 0); //

require_once('SssS_SocketController.inc');
$oServer = new SssS_SocketController();

/*
// don't timeout
set_time_limit (0);

// for now just start the room
$oSSR = new SssS_ShellScriptRunner();
$aRes = $oSSR->doScript('daemon.php >> data/log/chatRoomServer.log &');
if (0 !== $aRes['scriptExitCode']) {
	var_dump($aRes); exit('can not start chatRoomServer');
} // if not started

exit('launched room server daemon.php, it has written it\'s pid to the file specified in it\'s config
logging to data/log/chatRoomServer.log
');
*/

/*
// create socket
$rSocket = socket_create(AF_INET, SOCK_STREAM, 0) or die("Could not create socket\n");

// bind socket to port
$bResult = socket_bind($rSocket, $aS['host'], $aS['port']) or die("Could not bind to socket\n");

// start listening for connections
$bResult = socket_listen($rSocket, 3) or die("Could not set up socket listener\n");

echo "Waiting for connections...\n";

// accept incoming connections
// spawn another socket to handle communication
$aU['A']['rSpawn'] = socket_accept($rSocket) or die("Could not accept incoming
connectionA\n");

echo "Received connection request A\n";

// write a welcome message to the client A
$sWelcome = sprintf($aS['welcome'], $aU['A']['name']);
write2Client('A', $sWelcome);


echo "Waiting for next connection...\n";
// accept incoming connections
// spawn another socket to handle communication
$aU['B']['rSpawn'] = socket_accept($rSocket) or die("Could not accept incoming
connectionB\n");

echo "Received connection request B\n";

// write a welcome message to the client B
$sWelcome = sprintf($aS['welcome'], $aU['B']['name']);
write2Client('B', $sWelcome);

echo "Both on both free to chat\n";

// keep looping and looking for client input
do {
	// read client A input
	readClientInput('A');
	// read client B input
	readClientInput('B');
	}
} while (true);
/* * * *\ server.php (CC) Luke JZ aka SwissalpS /* * * */
?>
