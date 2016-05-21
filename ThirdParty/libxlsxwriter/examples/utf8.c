/*
 * A simple Unicode UTF-8 example using libxlsxwriter.
 *
 * Note: The source file must be UTF-8 encoded.
 *
 * Copyright 2014-2015, John McNamara, jmcnamara@cpan.org
 *
 */

#include "xlsxwriter.h"
#include <locale.h>

int main() {

    lxw_workbook  *workbook  = workbook_new("utf8.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

	worksheet_write_string(worksheet, 2, 1, "Это фраза на русском!", NULL);

    setlocale(LC_ALL, "zh_CN.utf-8");

    worksheet_write_string(worksheet, 2, 2, "曼珠菩提引三生生", NULL);

    setlocale(LC_ALL, "zh_CN.GBK");

    return workbook_close(workbook);
}
