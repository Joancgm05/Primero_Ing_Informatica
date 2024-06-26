library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity funciones2_tb is

end funciones2_tb;

architecture tb of funciones2_tb is

    component funciones2
        port (a  : in std_logic;
              b  : in std_logic;
              c  : in std_logic;
              d  : in std_logic;
              g0 : out std_logic;
              g1 : out std_logic;
              g2 : out std_logic;
              g3 : out std_logic;
              g4 : out std_logic;
              g5 : out std_logic;
              g6 : out std_logic;
              g7 : out std_logic);
     end component;
     
     signal a  : std_logic := '0';
     signal b  : std_logic := '0';
     signal c  : std_logic := '0';
     signal d  : std_logic := '0';
     signal g0 : std_logic;
     signal g1 : std_logic;
     signal g2 : std_logic;
     signal g3 : std_logic;
     signal g4 : std_logic;
     signal g5 : std_logic;
     signal g6 : std_logic;
     signal g7 : std_logic; 
     constant Tb_semiPeriod : time := 10 ns;
     
     signal TbSimEnded : std_logic := '0';
     
begin

dut: funciones2
    port map (a => a,
              b => b,
              c => c,
              d => d,
              g0 => g0,
              g1 => g1,
              g2 => g2,
              g3 => g3,
              g4 => g4,
              g5 => g5,
              g6 => g6,
              g7 => g7);
              
              -- Stimuli generation
              d <= not d after Tb_semiPeriod  when TbSimEnded /= '1' else '0';
              c <= not c after Tb_semiPeriod*2 when TbSimEnded /= '1' else '0';
              b <= not b after Tb_semiPeriod*4 when TbSimEnded /= '1' else '0';
              a <= not a after Tb_semiPeriod*8 when TbSimEnded /= '1' else '0';
              
              -- End of simulation: multiply Tb_semiPeriod by 2^nº variables
              TbSimEnded <= '1' after 16 * Tb_semiPeriod; -- 2^4 = 16

end tb;