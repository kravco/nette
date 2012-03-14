<?php

/**
 * Common code for Template test cases.
 */

use Nette\Caching\Storages\PhpFileStorage;



class MockHttpResponse implements Nette\Http\IResponse
{
	public $headers = array();

	public function setCode($code) {}
	public function getCode() {}
	public function addHeader($name, $value) {}
	public function setHeader($name, $value) { $this->headers[$name] = $value; }
	public function setContentType($type, $charset = NULL) {}
	public function redirect($url, $code = self::S302_FOUND) {}
	public function setExpiration($seconds) {}
	public function isSent() {}
	public function getHeaders() {}
	public function setCookie($name, $value, $expire, $path = NULL, $domain = NULL, $secure = NULL, $httpOnly = NULL) {}
	public function deleteCookie($name, $path = NULL, $domain = NULL, $secure = NULL) {}

}



class MockCacheStorage extends PhpFileStorage
{
	public $phtml = array();

	public function __construct()
	{
		parent::__construct(TEMP_DIR);
	}

	public function read($key)
	{
		return NULL;
	}

	public function write($key, $data, array $dp)
	{
		$this->phtml[basename($this->hint)] = codefix($data);
	}

}



function codefix($s)
{
	$s = preg_replace("#(?<=['_])[a-z0-9]{10,}(?=['_])#", 'xxx', $s);
	$s = preg_replace('#source file:.*#', '', $s);
	return $s;
}
