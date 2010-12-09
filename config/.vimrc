"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" General
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"since 7.3
set undofile
set undodir=/tmp/vim/undo
"end 7.3

"显示行号 set nu/set nonu
set number
"set ruler
"auto change dir
set autochdir
" 设置编码
set enc=utf-8
" 设置文件编码
set fenc=utf-8
" 设置文件编码检测类型及支持格式
set fencs=utf-8,cp936,gbk,ucs-bom,gb18030,cp936,enu-cs
" 保存文件格式
set fileformats=unix,dos

"不使用vi键盘模式，而是使用vim键盘模式
set nocompatible

" Turn backup on
set backup
" Set backup directory
set backupdir=$HOME/.vim/backup

"设置鼠标可右键复制
set mouse=v
"set selection=exclusive
set selectmode=key

" 设定文件浏览器目录为当前目录
set bsdir=buffer
" 指定菜单语言
set langmenu=en_US.UTF-8

" 设置语法高亮度 sy on/sy off
syntax on

"自动换行
"set lbr

" tab宽度
set expandtab
set tabstop=4
set shiftwidth=4
set cindent shiftwidth=4
set autoindent shiftwidth=4

"设置自动折行 set wrap/set wrap!
set wrap
""不要闪烁，不要蜂鸣 no visual bell, and no beep. oh,yeah!
set novisualbell
"set noerrorbells
set vb t_vb="."
"状态行显示的内容（包括文件类型和解码）
"set statusline=%F%m%r%h%w\ FORMAT=%{&ff}\ TYPE=%Y\ POS=%l,%v\ %p%%\ %{strftime(\"%y-%m-%d\ -\ %H:%M\")}
set statusline=%<%f\ %h%m%r%=%k%{&ff}\ [%{(&fenc==\"\")?&enc:&fenc}%{(&bomb?\",BOM\":\"\")}]\ %-14.(%l,%c%V%)\ %P
set laststatus=2
"命令行高度
set cmdheight=1

" 状态行颜色
highlight StatusLine guifg=SlateBlue guibg=Yellow
"highlight StatusLineNC guifg=Gray guibg=White


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Color
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" 使用调色板
" 按照时间改变调色板
colorscheme peachpuff
"colorscheme default

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Search
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"查找时大小写敏感
"set igsearch

" Enable magic matching
set magic

" Show matching bracets
" 查找结果高亮度显示
set showmatch

" Highlight search things
set hlsearch

" Ignore case when searching
" 查找时若有大写则敏感
set ignorecase
set smartcase

" Incremental match when searching
" 动态查找 set ic for short
set incsearch

"不循环搜索 no wrap scan
""set nowrapscan

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Indent
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"自动缩进
"依文件类型自动缩进 
filetype plugin indent on

"继承前一行缩进方式 set ai for short
set autoindent 

" Smart indet
set smartindent

" C-style indeting
set cindent

" Set tabstop width
set tabstop=4
set shiftwidth=4
set softtabstop=4

" Enable filetype plugin
filetype on
filetype plugin on
filetype indent on

" Set <BS> delete fake tabs
set smarttab

" Insert spaces instead of real tabs
set expandtab


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Completation
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"自动补全
set completeopt=longest,menu

"括号自动补全
":inoremap ( ()<ESC>i
":inoremap ) <c-r>=ClosePair(’)')<CR>
":inoremap { {}<ESC>i
":inoremap } <c-r>=ClosePair(’}')<CR>
":inoremap " ""<ESC>i
":inoremap " <c-r>=ClosePair(’"’)<CR>
":inoremap ' ''<ESC>i
":inoremap ' <c-r>=ClosePair(’\'’)<CR>
":inoremap [ []<ESC>i
"":inoremap ] <c-r>=ClosePair(’]')<CR>
":inoremap < <><ESC>i
":inoremap > <c-r>=ClosePair(’>’)<CR>

function ClosePair(char)
	if getline(’.')[col(’.') - 1] == a:char
		return “\<Right>”
	else
		return a:char
	endif
endf

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" CTags
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" Auto finding
" set tags=tags;
" 增强检索功能
set tags=./tags,./../tags,./**/tags,../../tags
" Sort by name
let Tlist_Sort_Type = "name"

" Use right window
let Tlist_Use_Right_Window = 1

" Enable auto update
let Tlist_Auto_Update = 1

" Set compart format
let Tlist_Compart_Format = 1

" Set exit by window
let Tlist_Exit_OnlyWindow = 1

" Disable auto close
let Tlist_File_Fold_Auto_Close = 0

" Disable fold column
let Tlist_Enable_Fold_Column = 0

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Cscope
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" Use both cscope and ctag
set cscopetag

" Show msg when cscope db added
set cscopeverbose

" Use tags for definition search first
set cscopetagorder=1

" Use quickfix window to show cscope results
set cscopequickfix=s-,g-,d-,c-,t-,e-,f-,i-

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Mappings
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
map <Up> gk
map <Down> gj
map <c-p> :bp<cr>
map <c-n> :bn<cr>
nnoremap gn :bn<cr>
nnoremap gp :bp<cr>

"编译
nmap <F7> :make<cr>
nmap mk :make<cr><cr>
"运行
nmap <F8> :make run<cr>

"添加时间戳
map <F5> O<C-R>=strftime("%c")<CR><Esc>o
"nmap <F7> :!sdcv -n <C-R>=expand("<cword>")<CR><CR>
"nmap <C-[> :!sdcv "<cword>" <C-R>=expand("<cword>")<CR><CR>
"nmap <C-B> :!"<cword>"<CR>

map <F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR>
let OmniCpp_MayCompleteScope = 1
let OmniCpp_ShowPrototypeInAbbr = 1
set completeopt=menu

"""""""""""""""""""""""""""""""""""""""""""
" Make
"""""""""""""""""""""""""""""""""""""""""""
"设置make来更新conky设置
au BufNewFile,BufRead *conkyrc* set makeprg=pkill\ conky&conky\ -c\ %\ 2>~/.conky/%.log&
au BufNewFile,BufRead *conkyrc* set filetype=conkyrc
au BufNewFile,BufRead *tint2rc* set makeprg=pkill\ tint2&tint2\ -c\ %&
au BufNewFile,BufRead .trayrc set makeprg=pkill\ trayer&trayer\ `cat\ .trayrc`&
au BufNewFile,BufRead lrcdis set makeprg=pkill\ lrcdis&lrcdis\ -m\ fifo
"设置make来更新openbox配置
au BufNewFile,BufRead rc.xml set makeprg=openbox\ --reconfigure&

au BufNewFile,BufRead *.cc set makeprg=g++\ %\ -o\ %.out&

"autocmd
"autocmd FileType cc source ~/.vim/myplugin/cpp.vim

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Fold
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

if has("autocmd")
	augroup cprog
		autocmd FileType java,c,cpp,cc,javascript,css,php,pl,sed,awk,sh set formatoptions=croql cindent comments=sr:/*,mb:*,el:*/,:// expandtab foldcolumn=4 foldmethod=expr foldexpr=MyFoldfun(v:lnum)
	augroup END
else
	set foldcolumn=4
	"set foldmethod=expr
	set foldexpr=MyFoldfun(v:lnum)
endif


"设置xml文档依缩进折叠
autocmd FileType xml,html,xsl,xhtml,htm,xhtm,svg,xsd,php,vimrc,python set foldmethod=indent
"set foldmethod=marker
"python设置
autocmd FileType python setlocal makeprg=gnome-terminal\ -e\ ./%
autocmd FileType sh setlocal makeprg=xterm\ -e\ ./%

"光标行折行总是打开的
"set foldopen=all
"光标离开时折行自动关闭
"set foldclose=all

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Commet
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"sh脚本自动注释
let g:BASH_AuthorName='csip'
let g:BASH_Email='amoblin@gmail.com'
let g:BASH_Company='bistu'

"augroup math
"	au!
"	au BufEnter *.m set makeprg=octave\ --persist\ %
"augroup END

"""""""""""""""""""""""""""
" Latex file settings
"""""""""""""""""""""""""""

augroup tex
	au!
	au BufEnter *.tex set makeprg=pdflatex\ %
augroup END
let g:Tex_CompileRule_dvi="latex -src-specials -interaction=nonstopmode $*"

""""""""""""""""""""""""""""""""""""""""""""""
" rest file setting
""""""""""""""""""""""""""""""""""""""""""""""
autocmd FileType rst setlocal makeprg=rake\ html


""""""""""""""""""""""""""""""
" c source file settings
""""""""""""""""""""""""""""""

"c风格括号折叠
function MyFoldfun(lineNum)
	if getline(a:lineNum+1)=~'^{'
		return 'a1'
	elseif getline(a:lineNum)=~'^}'
		return 's1'
	elseif getline(a:lineNum)=~'.\+{.\+}'
		return '='
	elseif getline(a:lineNum)=~'.\+}'
		return 's1'
	elseif getline(a:lineNum)=~'.\+{'
		return 'a1'
	else
		return '='
	endif
endfunction

