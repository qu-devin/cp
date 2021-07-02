set gfn=@Fixedsys:h20
set guioptions-=m
set guioptions-=T
set guioptions-=r

call plug#begin()

Plug 'Raimondi/delimitMate'

call plug#end()

filetype plugin on

set expandtab
set tabstop=4
set softtabstop=4
set shiftwidth=4
set autoindent

set encoding=utf-8

syntax on

" true colours
set t_Co=256

set nu rnu " relative line numbering
set clipboard=unnamed " public copy/paste register
set noswapfile " doesn't create swap files

set backspace=indent,eol,start " let backspace delete over lines
set autoindent " enable auto indentation of lines
set smartindent " allow vim to best-effort guess the indentation

set lazyredraw "redraws the screne when it needs to
set showmatch "highlights matching brackets
set incsearch "search as characters are entered
set hlsearch "highlights matching searches

"clears highlights
nnoremap // :noh<return>

" run code
nnoremap <f5> :w <bar> !g++ -std=c++17 -O2 % -Wall<cr><cr>
nnoremap <f6> :!a.exe<cr><cr>
