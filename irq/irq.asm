


global irq12_handler
extern mouse_handler_c

irq12_handler:
    pusha
    call mouse_handler_c
    popa
    iretd
