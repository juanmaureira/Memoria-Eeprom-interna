/*****************************************************************
Función: 	Escribe un arreglo en la memoria eeprom del uC
Comentario: 
*****************************************************************/
void WriteArray(long int dir, char *data, int size){
int i;
   for(i=0;i<size;i++,dir++){
      write_eeprom(dir,*(data+i));
      delay_cycles(5);
   }
   write_eeprom(dir,0x00);
   delay_cycles(5);
}
/*****************************************************************
Función: 	Lee un arreglo de la memoria eeprom del uC
Comentario: 
*****************************************************************/
void ReadArray(long int dir,char *array1, int size){
int i;
   for(i=0;i<size;i++,dir++){
      *(array1+i)=read_eeprom(dir);
       delay_ms(5);   
   }   
}
/*****************************************************************
Función: 	escribe un float en la eeprom del uC
Comentario: 
*****************************************************************/
long int escribe_eeprom(long int address,float data){                                              
														 	   	 										
int buffer[sizeof(float)];							  
int index;

  memcpy(buffer,&data,sizeof(float));					 
  														 
  for (index=0;index<sizeof(float);index++)		
        write_eeprom(address++,buffer[index]);

  return(address);			
}                                                                                             
/*****************************************************************
Función: 	Lee un float de la memoria eeprom del uC
Comentario: 
*****************************************************************/
float lee_eeprom(long int address){                                                               														 
	int buffer[sizeof(float)]; 						 
	float temp; 										
	int index;
	for (index=0;index<sizeof(float);index++)		 
        buffer[index] = read_eeprom(address++);   
	memcpy(&temp,buffer,sizeof(float));				 										 
	return(temp);
}
/*****************************************************************
Función: 	Lee un word de la memoria eeprom del uC
Comentario: 
*****************************************************************/
long read_16bits_eeprom(long dir){
	long data;
	data=read_eeprom(dir);
	dir++;
	data<<=8;
	data|=read_eeprom(dir);
	return data;
}
/*****************************************************************
Función: 	Escribe un word de la memoria eeprom del uC
Comentario: 
*****************************************************************/
long write_16bits_eeprom(long dir, long data){
	int lo, hi;
	lo=data;
	hi=data>>8;
	write_eeprom(dir,hi);
	delay_cycles(2);
	dir++;
	write_eeprom(dir,lo);
	dir++;
	return dir;	
}