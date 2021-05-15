ENTRY(RESET_Handler)

MEMORY
{
	FLASH(RX): ORIGIN =   0x08000000 ,LENGTH = 2048k 
	SRAM1(RWX) : ORIGIN = 0x20000000, LENGTH = 192K

}


SECTIONS
{
	.text :
	{
		*(.vector)
		*(.text)
		*(.rodata)
		*(.comment)
		. = ALIGN(4);
		end_of_text = .; /* record the address of the end of code section */
	
	}>FLASH
	
	.data : 
	{
		. = ALIGN(4);
		start_of_data = .;
		*(.data)
		. = ALIGN(4);
		end_of_data = .;     /* record the address of the end of data section */

	}> SRAM1 AT>FLASH   
	.bss :
	{
		. = ALIGN(4);
	_strat_of_bss = .;
	*(.bss)
		. = ALIGN(4);
	_end_of_bss = .;     /* record the address of the end of bss unitialized section */
	}>SRAM1


}