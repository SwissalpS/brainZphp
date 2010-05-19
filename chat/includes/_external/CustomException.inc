<?php
/**
 * CustomException.inc
 * taken from comments on {@link http://php.net} and adapdet slightly to my likings
 * @author SwissalpS 20100422_132043
 *
 * @author ask at nilpo dot com 27-May-2009 07:19
 *
 * If you intend on creating a lot of custom exceptions, you may find this code useful.
 * I've created an interface and an abstract exception class that ensures that all parts of the built-in Exception class are preserved in child classes.
 * It also properly pushes all information back to the parent constructor ensuring that nothing is lost.
 * This allows you to quickly create new exceptions on the fly.
 * It also overrides the default __toString method with a more thorough one.
 *
 * Read source code for usage example
 * @package uroXbrainZ
 * @filesource
 */
// Exceptions were officially introduced in 5
if (version_compare('5', phpversion(), '>')) return;

/**
 * taken from comments on {@link http://php.net} and adapdet slightly to my likings
 * @author SwissalpS 20100422_132043
 *
 * @author ask at nilpo dot com 27-May-2009 07:19
 *
 * If you intend on creating a lot of custom exceptions, you may find this code useful.
 * @package uroXbrainZ
 */
/*
 *
 * Usage:
 * Now you can create new exceptions in one line:
 * &lt;?php<br />
 *   class TestException extends CustomException {}\<br />
 * ?>
 *
 * Here's a test that shows that all information is properly preserved throughout the backtrace.
 *
 * &lt;?php
 * function exceptionTest()
 * {
 *		try {
 *			throw new TestException();
 *		}
 *		catch (TestException $e) {
 *			echo "Caught TestException ('{$e->getMessage()}')\n{$e}\n";
 *		}
 *		catch (Exception $e) {
 *			echo "Caught Exception ('{$e->getMessage()}')\n{$e}\n";
 *		}
 * }
 *
 * echo '<pre>' . exceptionTest() . '</pre>';
 * ?>
 *
 * Here's a sample output:
 *
 * Caught TestException ('Unknown TestException')
 * TestException 'Unknown TestException' in C:\xampp\htdocs\CustomException\CustomException.php(31)
 * #0 C:\xampp\htdocs\CustomException\ExceptionTest.php(19): CustomException->__construct()
 * #1 C:\xampp\htdocs\CustomException\ExceptionTest.php(43): exceptionTest()
 * #2 {main}
 */
interface IException {
	/* Protected methods inherited from Exception class */

	/**
	 * Redefinition of inherited protected method
	 *
	 * long description blabala
	 *
	 * @return string Exception message
	 * @author ask at nilpo dot com 27-May-2009 07:19
	 * @version 20100517_100131 (CC) Luke JZ aka SwissalpS
	 */
	public function getMessage();				// Exception message

	/**
	 * Redefinition of inherited protected method
	 *
	 * @return int User-defined Exception code
	 * @version 20100517_100131 (CC) Luke JZ aka SwissalpS
	 */
	public function getCode();					// User-defined Exception code

	/**
	 * Redefinition of inherited protected method
	 *
	 * @return string Source filename
	 * @author ask at nilpo dot com 27-May-2009 07:19
	 * @version 20100517_100131 (CC) Luke JZ aka SwissalpS
	 */
	public function getFile();					// Source filename

	/**
	 * Redefinition of inherited protected method
	 *
	 * @return integer Source line
	 * @author ask at nilpo dot com 27-May-2009 07:19
	 * @version 20100517_100131 (CC) Luke JZ aka SwissalpS
	 */
	public function getLine();					// Source line

	/**
	 * Redefinition of inherited protected method
	 *
	 * @return array An array of the backtrace()
	 * @author ask at nilpo dot com 27-May-2009 07:19
	 * @version 20100517_100131 (CC) Luke JZ aka SwissalpS
	 */
	public function getTrace();					// An array of the backtrace()

	/**
	 * Redefinition of inherited protected method
	 *
	 * @return string Formated string of trace
	 * @author ask at nilpo dot com 27-May-2009 07:19
	 * @version 20100517_100131 (CC) Luke JZ aka SwissalpS
	 */
	public function getTraceAsString();			// Formated string of trace


	/* Overrideable methods inherited from Exception class */

	/**
	 * Override of inherited protected method
	 *
	 * @return string Exception message and more
	 * @author ask at nilpo dot com 27-May-2009 07:19
	 * @version 20100517_100131 (CC) Luke JZ aka SwissalpS
	 */
	public function __toString();				// formated string for display

	/**
	 * Override of inherited method
	 *
	 * @return Exception a new Exception subclass
	 * @author ask at nilpo dot com 27-May-2009 07:19
	 * @version 20100517_100131 (CC) Luke JZ aka SwissalpS
	 */
	public function __construct($message = null, $code = 0);
} // IException

/**
 * CustomException
 *
 * @author ask at nilpo dot com 27-May-2009 07:19
 * If you intend on creating a lot of custom exceptions, you may find this code useful.
 * I've created an interface and an abstract exception class that ensures that all parts of the built-in Exception class are preserved in child classes.
 * It also properly pushes all information back to the parent constructor ensuring that nothing is lost.
 * This allows you to quickly create new exceptions on the fly.
 * It also overrides the default __toString method with a more thorough one.
 *
 * Usage:
 * <code>
 * Now you can create new exceptions in one line:
 * <?php
 *   class TestException extends CustomException {}
 * ?>
 *
 * Here's a test that shows that all information is properly preserved throughout the backtrace.
 *
 * <?php
 * function exceptionTest()
 * {
 *		try {
 *			throw new TestException();
 *		}
 *		catch (TestException $e) {
 *			echo "Caught TestException ('{$e->getMessage()}')\n{$e}\n";
 *		}
 *		catch (Exception $e) {
 *			echo "Caught Exception ('{$e->getMessage()}')\n{$e}\n";
 *		}
 * }
 *
 * echo '<pre>' . exceptionTest() . '</pre>';
 * ?>
 *
 * Here's a sample output:
 *
 * Caught TestException ('Unknown TestException')
 * TestException 'Unknown TestException' in C:\xampp\htdocs\CustomException\CustomException.php(31)
 * #0 C:\xampp\htdocs\CustomException\ExceptionTest.php(19): CustomException->__construct()
 * #1 C:\xampp\htdocs\CustomException\ExceptionTest.php(43): exceptionTest()
 * #2 {main}
 * </code>
 *
 * @package uroXbrainZ
 * @version 20100517_095408 (CC) Luke JZ aka SwissalpS
 */
abstract class CustomException extends Exception implements IException {
	protected $message = 'Unknown exception';	// Exception message
	private   $string;							// Unknown
	protected $code = 0;						// User-defined exception code
	protected $file;							// Source filename of exception
	protected $line;							// Source line of exception
	private   $trace;							// Unknown

	public function __construct($message = null, $code = 0) {
		if (!$message) {
			throw new $this('Unknown '. get_class($this));
		}
		parent::__construct($message, $code);
	} // __construct

	public function __toString() {
		return get_class($this)
				. " '{$this->message}' in {$this->file}({$this->line})\n"
				. "{$this->getTraceAsString()}";
	} // __toString
} // CustomException
?>
