<?php

$html = "<div><a href='http://google.com'>Go to Google</a></div>";
$html1 = "<html><div><a href='http://google.com'>Go to Google</a></div></html>";
$html = <<< 'HTML'
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>
      Hello&nbsp;world!
    </title>
  </head>
  <body>
    <h1>
      Hello&nbsp;world!
    </h1>
  </body>
</html>
HTML;
$html4 = <<< 'HTML'
<html lang="en">
  <body><h1>Hello&nbsp;world!</h1></body>
</html>
HTML;
$dom = MyHTML\DOMDocument::loadHTML($html);
//$dom = DOMDocument::loadHTML($html, LIBXML_HTML_NODEFDTD | LIBXML_HTML_NOIMPLIED);
var_dump($dom->saveHTML());