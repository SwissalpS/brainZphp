#!/bin/bash
# $Id: makedoc.sh,v 1.2 2007/12/10 01:11:19 ashnazg Exp $

#/**
#  * makedoc - PHPDocumentor script to save your settings
#  *
#  * Put this file inside your PHP project homedir, edit its variables and run whenever you wants to
#  * re/make your project documentation.
#  *
#  * The version of this file is the version of PHPDocumentor it is compatible.
#  *
#  * It simples run phpdoc with the parameters you set in this file.
#  * NOTE: Do not add spaces after bash variables.
#  *
#  * @copyright 		makedoc.sh is part of PHPDocumentor project {@link http://freshmeat.net/projects/phpdocu/} and its LGPL
#  * @author			Roberto Berto <darkelder (inside) users (dot) sourceforge (dot) net>
#  * @version			Release-1.1.0
#  */


##############################
# should be edited
##############################

#/**
#  * title of generated documentation, default is 'Generated Documentation'
#  *
#  * @var				string TITLE
#  */
TITLE="uroXbrainZ source documentation"

#/**
#  * name to use for the default package. If not specified, uses 'default'
#  *
#  * @var				string PACKAGES
#  */
PACKAGES="uroXbrainZ"

#/**
#  * name of a directory(s) to parse directory1,directory2
#  * $PWD is the directory where makedoc.sh
#  *
#  * @var				string PATH_PROJECT
#  */
PATH_PROJECT=../
#$PWD/includes

#/**
#  * path of PHPDoc executable
#  *
#  * @var               string PATH_PHPDOC
#  */
PATH_PHPDOC=/Volumes/UNIXb/gitSwissalpS/PhpDocumentor/phpdoc
#/ImgSrach/public/public_web/PhpDocumentor/phpdoc

#/**
#  * where documentation will be put
#  *
#  * @var				string PATH_DOCS
#  */
PATH_DOCS=$PWD/SwissalpS_MashS

#/**
#  * what outputformat to use (html/pdf)
#  *
#  * @var				string OUTPUTFORMAT
#  */
OUTPUTFORMAT=HTML

#/**
#  * converter to be used
#  *
#  * @var				string CONVERTER
#  */
CONVERTER=SwissalpS
#Smarty

#/**
#  * template to use
#  *
#  * @var				string TEMPLATE
#  */
TEMPLATE=MashS
#HTML:default:default	--works ugly
#HTML:default:earthli	--works informative icons
#HTML:default:l0l33t	--works
#HTML:default:phpdoc.de --works
#HTML:default:phpedit	--works
#HTML:default:phphtmllib--works
#HTML:default:DOM/default		--too pale for my taste
#HTML:default:DOM/earthli		-+I like the informative icons
#HTML:default:DOM/l0l33t		--too pale,small and dotted but works
#HTML:default:DOM/phpdoc.de   --works, ok
#HTML:default:DOM/phphtmllib  -+works, surprisingly nice, may need some color wash, but not very bright :-)
#HTML:Smarty:default  --works, needs color workover and possibly font too
#HTML:Smarty:HandS	  -+works, nice brownish
#HTML:Smarty:PHP	  -+works, nice PHP.org style
#PDF:default:default  --works if really need be
#CHM:default:default  --havn't tested output but seems to work
#XML:DocBook:peardoc2 --fails
#FAZIT: make a Smarty template based on HandS or PHP that uses the icons from earthli and function varttype color difference from php

#/**
#  * parse elements marked as private
#  *
#  * @var				bool (on/off)			PRIVATE
#  */
PRIVATE=off

# make documentation
"$PATH_PHPDOC" -d "$PATH_PROJECT" -t "$PATH_DOCS" -ti "$TITLE" -dn $PACKAGES \
-o $OUTPUTFORMAT:$CONVERTER:$TEMPLATE -pp $PRIVATE


# vim: set expandtab :
