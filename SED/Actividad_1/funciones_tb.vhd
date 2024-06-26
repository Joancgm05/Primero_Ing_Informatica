library ieee;
use ieee.std_logic_1164.all;

entity funciones_tb is
end funciones_tb;

architecture tb of funciones_tb is

    component funciones
        port (a : in std_logic;
              b : in std_logic;
              f0 : out std_logic;
              f1 : out std_logic;
              f2 : out std_logic;
              f3 : out std_logic;
              f4 : out std_logic;
              f5 : out std_logic;
              f6 : out std_logic);
    end component;
    
    signal a : std_logic := '0';
    signal b : std_logic := '0';
    signal f0 : std_logic;
    signal f1 : std_logic;
    signal f2 : std_logic;
    signal f3 : std_logic;
    signal f4 : std_logic;
    signal f5 : std_logic;
    signal f6 : std_logic;
    
    constant Tb_semiPeriod : time := 10 ns; -- Put right period here
    
    signal TbSimEnded : std_logic := '0';
              
begin

    dut : funciones
    port map (a => a,
              b => b,
              f0 => f0,
              f1 => f1,
              f2 => f2,
              f3 => f3,
              f4 => f4,
              f5 => f5,
              f6 => f6);
              
    -- Stimuli generation
    b <= not b after Tb_semiPeriod  when TbSimEnded /= '1' else '0';
    a <= not a after Tb_semiPeriod*2  when TbSimEnded /= '1' else '0';
    
    -- End of simulation: multiply Tb_semiPeriod by 2^nº variables
    TbSimEnded <= '1' after 4 * Tb_semiPeriod;
end tb;