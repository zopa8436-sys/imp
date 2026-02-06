#pragma once

// ���������� ��������� - ���� ����� � �������
const short BLACK   = 0b0000;
const short BLUE    = 0b0001;
const short GREEN   = 0b0010;
const short CYAN    = 0b0011;
const short RED     = 0b0100;
const short MAGENTA = 0b0101;
const short YELLOW  = 0b0110;
const short GRAY    = 0b0111;

const short LTBLACK   = 0b1000;
const short LTBLUE    = 0b1001;
const short LTGREEN   = 0b1010;
const short LTCYAN    = 0b1011;
const short LTRED     = 0b1100;
const short LTMAGENTA = 0b1101;
const short LTYELLOW  = 0b1110;
const short WHITE     = 0b1111;

// ����� �� ������ ����
const short BLACK_ON_BLACK     = BLACK   | BLACK << 4;
const short BLUE_ON_BLACK      = BLUE    | BLACK << 4;
const short GREEN_ON_BLACK     = GREEN   | BLACK << 4;
const short CYAN_ON_BLACK      = CYAN    | BLACK << 4;
const short RED_ON_BLACK       = RED     | BLACK << 4;
const short MAGENTA_ON_BLACK   = MAGENTA | BLACK << 4;
const short YELLOW_ON_BLACK    = YELLOW  | BLACK << 4;
const short GRAY_ON_BLACK      = GRAY    | BLACK << 4;

const short LTBLACK_ON_BLACK   = LTBLACK   | BLACK << 4;
const short LTBLUE_ON_BLACK    = LTBLUE    | BLACK << 4;
const short LTGREEN_ON_BLACK   = LTGREEN   | BLACK << 4;
const short LTCYAN_ON_BLACK    = LTCYAN    | BLACK << 4;
const short LTRED_ON_BLACK     = LTRED     | BLACK << 4;
const short LTMAGENTA_ON_BLACK = LTMAGENTA | BLACK << 4;
const short LTYELLOW_ON_BLACK  = LTYELLOW  | BLACK << 4;
const short WHITE_ON_BLACK     = WHITE     | BLACK << 4;

// ����� �� c���� ����
const short BLACK_ON_BLUE     = BLACK   | BLUE << 4;
const short BLUE_ON_BLUE      = BLUE    | BLUE << 4;
const short GREEN_ON_BLUE     = GREEN   | BLUE << 4;
const short CYAN_ON_BLUE      = CYAN    | BLUE << 4;
const short RED_ON_BLUE       = RED     | BLUE << 4;
const short MAGENTA_ON_BLUE   = MAGENTA | BLUE << 4;
const short YELLOW_ON_BLUE    = YELLOW  | BLUE << 4;
const short GRAY_ON_BLUE      = GRAY    | BLUE << 4;

const short LTBLACK_ON_BLUE   = LTBLACK   | BLUE << 4;
const short LTBLUE_ON_BLUE    = LTBLUE    | BLUE << 4;
const short LTGREEN_ON_BLUE   = LTGREEN   | BLUE << 4;
const short LTCYAN_ON_BLUE    = LTCYAN    | BLUE << 4;
const short LTRED_ON_BLUE     = LTRED     | BLUE << 4;
const short LTMAGENTA_ON_BLUE = LTMAGENTA | BLUE << 4;
const short LTYELLOW_ON_BLUE  = LTYELLOW  | BLUE << 4;
const short WHITE_ON_BLUE     = WHITE     | BLUE << 4;

// ����� �� ������� ����
const short BLACK_ON_GREEN     = BLACK   | GREEN << 4;
const short BLUE_ON_GREEN      = BLUE    | GREEN << 4;
const short GREEN_ON_GREEN     = GREEN   | GREEN << 4;
const short CYAN_ON_GREEN      = CYAN    | GREEN << 4;
const short RED_ON_GREEN       = RED     | GREEN << 4;
const short MAGENTA_ON_GREEN   = MAGENTA | GREEN << 4;
const short YELLOW_ON_GREEN    = YELLOW  | GREEN << 4;
const short GRAY_ON_GREEN      = GRAY    | GREEN << 4;

const short LTBLACK_ON_GREEN   = LTBLACK   | GREEN << 4;
const short LTBLUE_ON_GREEN    = LTBLUE    | GREEN << 4;
const short LTGREEN_ON_GREEN   = LTGREEN   | GREEN << 4;
const short LTCYAN_ON_GREEN    = LTCYAN    | GREEN << 4;
const short LTRED_ON_GREEN     = LTRED     | GREEN << 4;
const short LTMAGENTA_ON_GREEN = LTMAGENTA | GREEN << 4;
const short LTYELLOW_ON_GREEN  = LTYELLOW  | GREEN << 4;
const short WHITE_ON_GREEN     = WHITE     | GREEN << 4;

// ����� �� ������� ����
const short BLACK_ON_CYAN     = BLACK   | CYAN << 4;
const short BLUE_ON_CYAN      = BLUE    | CYAN << 4;
const short GREEN_ON_CYAN     = GREEN   | CYAN << 4;
const short CYAN_ON_CYAN      = CYAN    | CYAN << 4;
const short RED_ON_CYAN       = RED     | CYAN << 4;
const short MAGENTA_ON_CYAN   = MAGENTA | CYAN << 4;
const short YELLOW_ON_CYAN    = YELLOW  | CYAN << 4;
const short GRAY_ON_CYAN      = GRAY    | CYAN << 4;

const short LTBLACK_ON_CYAN   = LTBLACK   | CYAN << 4;
const short LTBLUE_ON_CYAN    = LTBLUE    | CYAN << 4;
const short LTGREEN_ON_CYAN   = LTGREEN   | CYAN << 4;
const short LTCYAN_ON_CYAN    = LTCYAN    | CYAN << 4;
const short LTRED_ON_CYAN     = LTRED     | CYAN << 4;
const short LTMAGENTA_ON_CYAN = LTMAGENTA | CYAN << 4;
const short LTYELLOW_ON_CYAN  = LTYELLOW  | CYAN << 4;
const short WHITE_ON_CYAN     = WHITE     | CYAN << 4;

// ����� �� ������� ����
const short BLACK_ON_RED     = BLACK   | RED << 4;
const short BLUE_ON_RED      = BLUE    | RED << 4;
const short GREEN_ON_RED     = GREEN   | RED << 4;
const short CYAN_ON_RED      = CYAN    | RED << 4;
const short RED_ON_RED       = RED     | RED << 4;
const short MAGENTA_ON_RED   = MAGENTA | RED << 4;
const short YELLOW_ON_RED    = YELLOW  | RED << 4;
const short GRAY_ON_RED      = GRAY    | RED << 4;

const short LTBLACK_ON_RED   = LTBLACK   | RED << 4;
const short LTBLUE_ON_RED    = LTBLUE    | RED << 4;
const short LTGREEN_ON_RED   = LTGREEN   | RED << 4;
const short LTCYAN_ON_RED    = LTCYAN    | RED << 4;
const short LTRED_ON_RED     = LTRED     | RED << 4;
const short LTMAGENTA_ON_RED = LTMAGENTA | RED << 4;
const short LTYELLOW_ON_RED  = LTYELLOW  | RED << 4;
const short WHITE_ON_RED     = WHITE     | RED << 4;

// ����� �� ������� ����
const short BLACK_ON_MAGENTA     = BLACK   | MAGENTA << 4;
const short BLUE_ON_MAGENTA      = BLUE    | MAGENTA << 4;
const short GREEN_ON_MAGENTA     = GREEN   | MAGENTA << 4;
const short CYAN_ON_MAGENTA      = CYAN    | MAGENTA << 4;
const short RED_ON_MAGENTA       = RED     | MAGENTA << 4;
const short MAGENTA_ON_MAGENTA   = MAGENTA | MAGENTA << 4;
const short YELLOW_ON_MAGENTA    = YELLOW  | MAGENTA << 4;
const short GRAY_ON_MAGENTA      = GRAY    | MAGENTA << 4;

const short LTBLACK_ON_MAGENTA   = LTBLACK   | MAGENTA << 4;
const short LTBLUE_ON_MAGENTA    = LTBLUE    | MAGENTA << 4;
const short LTGREEN_ON_MAGENTA   = LTGREEN   | MAGENTA << 4;
const short LTCYAN_ON_MAGENTA    = LTCYAN    | MAGENTA << 4;
const short LTRED_ON_MAGENTA     = LTRED     | MAGENTA << 4;
const short LTMAGENTA_ON_MAGENTA = LTMAGENTA | MAGENTA << 4;
const short LTYELLOW_ON_MAGENTA  = LTYELLOW  | MAGENTA << 4;
const short WHITE_ON_MAGENTA     = WHITE     | MAGENTA << 4;

// ����� �� ������ ����
const short BLACK_ON_YELLOW     = BLACK   | YELLOW << 4;
const short BLUE_ON_YELLOW      = BLUE    | YELLOW << 4;
const short GREEN_ON_YELLOW     = GREEN   | YELLOW << 4;
const short CYAN_ON_YELLOW      = CYAN    | YELLOW << 4;
const short RED_ON_YELLOW       = RED     | YELLOW << 4;
const short MAGENTA_ON_YELLOW   = MAGENTA | YELLOW << 4;
const short YELLOW_ON_YELLOW    = YELLOW  | YELLOW << 4;
const short GRAY_ON_YELLOW      = GRAY    | YELLOW << 4;

const short LTBLACK_ON_YELLOW   = LTBLACK   | YELLOW << 4;
const short LTBLUE_ON_YELLOW    = LTBLUE    | YELLOW << 4;
const short LTGREEN_ON_YELLOW   = LTGREEN   | YELLOW << 4;
const short LTCYAN_ON_YELLOW    = LTCYAN    | YELLOW << 4;
const short LTRED_ON_YELLOW     = LTRED     | YELLOW << 4;
const short LTMAGENTA_ON_YELLOW = LTMAGENTA | YELLOW << 4;
const short LTYELLOW_ON_YELLOW  = LTYELLOW  | YELLOW << 4;
const short WHITE_ON_YELLOW     = WHITE     | YELLOW << 4;

// ����� �� ����� ����
const short BLACK_ON_GRAY     = BLACK   | GRAY << 4;
const short BLUE_ON_GRAY      = BLUE    | GRAY << 4;
const short GREEN_ON_GRAY     = GREEN   | GRAY << 4;
const short CYAN_ON_GRAY      = CYAN    | GRAY << 4;
const short RED_ON_GRAY       = RED     | GRAY << 4;
const short MAGENTA_ON_GRAY   = MAGENTA | GRAY << 4;
const short YELLOW_ON_GRAY    = YELLOW  | GRAY << 4;
const short GRAY_ON_GRAY      = GRAY    | GRAY << 4;

const short LTBLACK_ON_GRAY   = LTBLACK   | GRAY << 4;
const short LTBLUE_ON_GRAY    = LTBLUE    | GRAY << 4;
const short LTGREEN_ON_GRAY   = LTGREEN   | GRAY << 4;
const short LTCYAN_ON_GRAY    = LTCYAN    | GRAY << 4;
const short LTRED_ON_GRAY     = LTRED     | GRAY << 4;
const short LTMAGENTA_ON_GRAY = LTMAGENTA | GRAY << 4;
const short LTYELLOW_ON_GRAY  = LTYELLOW  | GRAY << 4;
const short WHITE_ON_GRAY     = WHITE     | GRAY << 4;

// ����� �� ������-������ ����
const short BLACK_ON_LTBLACK     = BLACK   | LTBLACK << 4;
const short BLUE_ON_LTBLACK      = BLUE    | LTBLACK << 4;
const short GREEN_ON_LTBLACK     = GREEN   | LTBLACK << 4;
const short CYAN_ON_LTBLACK      = CYAN    | LTBLACK << 4;
const short RED_ON_LTBLACK       = RED     | LTBLACK << 4;
const short MAGENTA_ON_LTBLACK   = MAGENTA | LTBLACK << 4;
const short YELLOW_ON_LTBLACK    = YELLOW  | LTBLACK << 4;
const short GRAY_ON_LTBLACK      = GRAY    | LTBLACK << 4;

const short LTBLACK_ON_LTBLACK   = LTBLACK   | LTBLACK << 4;
const short LTBLUE_ON_LTBLACK    = LTBLUE    | LTBLACK << 4;
const short LTGREEN_ON_LTBLACK   = LTGREEN   | LTBLACK << 4;
const short LTCYAN_ON_LTBLACK    = LTCYAN    | LTBLACK << 4;
const short LTRED_ON_LTBLACK     = LTRED     | LTBLACK << 4;
const short LTMAGENTA_ON_LTBLACK = LTMAGENTA | LTBLACK << 4;
const short LTYELLOW_ON_LTBLACK  = LTYELLOW  | LTBLACK << 4;
const short WHITE_ON_LTBLACK     = WHITE     | LTBLACK << 4;
