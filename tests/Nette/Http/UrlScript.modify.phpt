<?php

/**
 * Test: Nette\Http\UrlScript modify.
 *
 * @author     David Grudl
 * @package    Nette\Http
 * @subpackage UnitTests
 */

use Nette\Http\UrlScript;



require __DIR__ . '/../bootstrap.php';



$uri = new UrlScript('http://nette.org:8080/file.php?q=search');
$uri->path = '/test/';
$uri->scriptPath = '/test/index.php';

Assert::same( '/test/index.php',  $uri->scriptPath );
Assert::same( 'http://nette.org:8080/test/',  $uri->baseUri );
Assert::same( '/test/',  $uri->basePath );
Assert::same( '?q=search',  $uri->relativeUri );
Assert::same( '',  $uri->pathInfo );
Assert::same( 'http://nette.org:8080/test/?q=search',  $uri->absoluteUri );
