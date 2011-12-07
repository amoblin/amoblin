#!/usr/bin/env python
# -*- coding:utf-8 -*-

import sys
import reportlab.rl_config
reportlab.rl_config.warnOnMissingFontGlyphs = 0
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.pdfgen import canvas
pdfmetrics.registerFont(TTFont('song', 'wqy-microhei.ttc'))
pdfmetrics.registerFont(TTFont('hei', 'wqy-zenhei.ttc'))

from reportlab.lib import fonts
fonts.addMapping('song', 0, 0, 'song')
fonts.addMapping('song', 0, 1, 'song')
fonts.addMapping('hei', 1, 0, 'hei')
fonts.addMapping('hei', 1, 1, 'hei')

import copy

from reportlab.platypus import Paragraph, SimpleDocTemplate, PageBreak
from reportlab.lib.styles import getSampleStyleSheet
stylesheet=getSampleStyleSheet()
normalStyle = copy.deepcopy(stylesheet['Normal'])
normalStyle.fontName ='song'
normalStyle.fontSize = 20
story = []

for line in open(sys.argv[1]).readlines():
    story.append(Paragraph(line, normalStyle))

doc = SimpleDocTemplate('hello.pdf')
doc.build(story)
