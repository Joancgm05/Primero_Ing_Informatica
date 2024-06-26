library ieee;
use ieee.std_logic_1164.all     ;

entity funciones67_tb is
end funciones67_tb;

architecture tb of funciones67_tb is

    component funciones67
        port (a  : in std_logic;
              b  : in std_logic;
              c  : in std_logic;
              d  : in std_logic;
              f1 : out std_logic;
              f2 : out std_logic);
    end component;
    
    signal a  : std_logic := '0';
    signal b  : std_logic := '0';
    signal c  : std_logic := '0';
    signal d  : std_logic := '0';
    signal f1 : std_logic;
    signal f2 : std_logic;
    
    constant Tb_semiPeriod : time := 10 ns;
    
    signal TbSimEnded : std_logic := '0';
   
begin

    dut : funciones67
    port map (a  => a,
              b  => b,
              c  => c,
              d  => d,
              f1 => f1,
              f2 => f2);
    
    d <= not d after Tb_semiPeriod   when TbSimEnded /= '1' else '0';
    c <= not c after Tb_semiPeriod*2 when TbSimEnded /= '1' else '0';
    b <= not b after Tb_semiPeriod*4 when TbSimEnded /= '1' else '0';
    a <= not a after Tb_semiPeriod*8 when TbSimEnded /= '1' else '0';
    
    TbSimEnded <= '1' after 16 * Tb_semiPeriod;
