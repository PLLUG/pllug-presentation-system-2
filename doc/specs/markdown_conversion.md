# Markdown Conversion


## General description of conversion process

  As a converter [Pandoc](http://pandoc.org/) universal document converter will be used. Pandoc is able to convert to/from number of Markdown formats. Pandoc also works with GitHub Flawored Markdown that we will use for our presentations.
  
  To convert document we need to run Pandoc with certain command line arguments as a separate process. This will require distribution of Pandoc together with our application (Windows, MacOS) and Pandoc as a dependency on Linux platform.

  Pandoc could parse markdown document and give document AST in a form of JSON. Thus we will be able to parse this intermediate JSON representation and use it in our application. PPS application will be able to use that intermediate JSON format and convert it to presentation. Then edited presentation could be imported back to the intermediate format and used by Pandoc. This gives an opportunity to use all supported by Pandoc formats in PPS. 
  

## Conversion strategy for Markdown

### Supported elements
For now we support only small number of elements of Markdown syntax:
* Level 1 headers
* Plain text
* Images
* Links
* Separators


### Conversion algorithm

In general, document structure should be converted to presentation structure during the import process. Original Markdown document should be divided into separate slides. Taking into account that document could or could not be adapted for such conversion we need special algorithm for that.

1. Search for separators and divide document onto parts between separators.
2. For each part - search for H1 headers and divide onto slides with H1 headers. Each H1 header will be title of the slide. Body of the H1 section will be content of the slide.
3. Divide further if slide content too long. To do that - move rest of the content (that could not be placed on slide) to the separate slide and duplicate previous slide title. Repeat until all content will be placed on the slides.







