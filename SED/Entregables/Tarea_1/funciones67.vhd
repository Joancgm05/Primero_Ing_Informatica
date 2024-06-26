library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity funciones67 is
    Port ( a : in STD_LOGIC;
           b : in STD_LOGIC;
           c : in STD_LOGIC;
           d : in STD_LOGIC;
           f1 : out STD_LOGIC;
           f2 : out STD_LOGIC);
end funciones67;

architecture Behavioral of funciones67 is

begin
    
    f1 <= (not a and not b and not c) or (not b and not c and not d) or
          (not a and b and c) or (b and c and not d) or (a and not b and c);
    f2 <= (a and b and c) or (not a and not b and c and d);

end Behavioral;
