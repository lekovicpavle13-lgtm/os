global irq1_handler
extern keyboard_handler_c

irq1_handler:
    pusha
    call keyboard_handler_c
    popa
    iretd
