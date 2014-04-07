#include <QString>
#include <QtTest>

#include "FiveAndFive.h"

class FiveAndFiveTests : public QObject {
    Q_OBJECT

public:
    FiveAndFiveTests( );

    static inline bool qFuzzyCompare( double p1, double p2, double delta ) {
        return ( qAbs( p1 - p2 ) <= delta * qMin( qAbs( p1 ), qAbs( p2 ) ));
    }

    private
Q_SLOTS:
    void testCase1_data( );
    void testCase1( );
};

FiveAndFiveTests::FiveAndFiveTests( ) {
}

void FiveAndFiveTests::testCase1_data( ) {
    QTest::addColumn<int>("number");
    QTest::addColumn<double>("expected");
    QTest::addColumn<bool>("isExpectedException");

    bool exception = true;
    bool no_exception = false;

    QTest::newRow( "fiveAndFive_02" ) << 0 << 0.0 << exception;
    QTest::newRow( "fiveAndFive_01" ) << 1 << 0.0 << exception;
    QTest::newRow( "fiveAndFive_03" ) << 4 << 0.0 << exception;
    QTest::newRow( "fiveAndFive_04" ) << 5 << 25.0 << no_exception;
    QTest::newRow( "fiveAndFive_05" ) << 6 << 0.0 << exception;
    QTest::newRow( "fiveAndFive_06" ) << 399995 << 159996000025.0 << no_exception;
    QTest::newRow( "fiveAndFive_07" ) << 400000 << 160000000000.0 << no_exception;
    QTest::newRow( "fiveAndFive_08" ) << 400001 << 0.0 << exception;
    QTest::newRow( "fiveAndFive_09" ) << 400005 << 0.0 << exception;
}

void FiveAndFiveTests::testCase1( ) {
    QFETCH( int, number );
    QFETCH( double, expected );
    QFETCH( bool, isExpectedException );

    double delta = 0.0001;

    FiveAndFive faf;

    try {
        double actual = faf.fiveAndFive( number );
        bool result = qFuzzyCompare( actual, expected, delta );
        if ( isExpectedException ) {
            QVERIFY2( false, "There is no exception." );
        } else {
            QString msg = QString( "\nActual: %1"
                    "\nExpected: %2"
                    "\nDelta: %3" ).arg( actual ).arg( expected ).arg( delta );
            QVERIFY2( result, msg.toStdString( ).c_str( ) );
        }

    } catch ( const LogicError& e ) {
        if ( !isExpectedException ) {
            QVERIFY2( false, "Exception was occur." );
        } else {
            QVERIFY2( true, "" );
        }
    } catch ( ... ) {
        QVERIFY2( false, "Uncaught exception." );
    }
}

QTEST_APPLESS_MAIN( FiveAndFiveTests )

#include "tst_FiveAndFiveTests.moc"
