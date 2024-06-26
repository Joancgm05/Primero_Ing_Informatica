library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity funciones is
    Port ( a : in STD_LOGIC;
           b : in STD_LOGIC;
           f0 : out STD_LOGIC;
           f1 : out STD_LOGIC;
           f2 : out STD_LOGIC;
           f3 : out STD_LOGIC;
           f4 : out STD_LOGIC;
           f5 : out STD_LOGIC;
           f6 : out STD_LOGIC);
end funciones;

architecture Behavioral of funciones is

begin

    f0 <=    not a;
    f1 <= a  and b;
    f2 <= a nand b;
    f3 <= a   or b;
    f4 <= a  nor b;
    f5 <= a  xor b;
    f6 <= a xnor b;

end Behavioral;