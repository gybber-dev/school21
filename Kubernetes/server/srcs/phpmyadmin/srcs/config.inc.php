<?php

declare(strict_types=1);

$cfg['blowfish_secret'] = '12345678901234567890123456789012'; /* YOU MUST FILL IN THIS FOR COOKIE AUTH! */

/**
 * Servers configuration
 */
$i = 0;

$i++;
/* Authentication type */
$cfg['Servers'][$i]['auth_type'] = 'cookie';
/* Server parameters */

// Change 'localhost' to 'mysql'. And add port number
$cfg['Servers'][$i]['host'] = 'sql-svc:3306';
$cfg['Servers'][$i]['user'] = 'wordpress';
$cfg['Servers'][$i]['password'] = '1234';
$cfg['Servers'][$i]['compress'] = false;
$cfg['Servers'][$i]['AllowNoPassword'] = true;
$cfg['UploadDir'] = '';
$cfg['SaveDir'] = '';


?>